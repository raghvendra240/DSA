link->>https://www.interviewbit.com/problems/valid-path/

int row[8]={0, 1, 1, 1, 0, -1, -1, -1};
int col[8]={1, 1, 0, -1, -1, -1, 0, 1};

bool outCircle(int i,int j,int radius,vector<int>&E,vector<int>&F)  
{
     for(int k=0; k<E.size(); k++)
     {
        if(pow((i-E[k]), 2)+pow((j-F[k]),2)<=pow(radius,2)) 
                   return false;
    }
    
    return true;
}
bool safe(int i,int j,int r,int c,int radius,vector<int>&E,vector<int>&F,vector<vector<bool>>&vis)
{
    if(i<0 || i>r || j<0 || j>c) 
      return false;
      
      if(vis[i][j])
        return false;
   
  if(outCircle(i,j,radius,E,F)==true)
      return true;
    
    
    
    return false;
}

bool dfs(int i,int j,int r,int c,int radius,vector<int>&E,vector<int>&F,vector<vector<bool>>&vis)
{
    if(i==r && j==c)
      return true;
   
      
      vis[i][j]=true;
      
      for(int k=0;k<8;k++)
      {
          int x=row[k]+i;
          int y=col[k]+j;
          
          if(safe(x,y,r,c,radius,E,F,vis))
          {
              if(dfs(x,y,r,c,radius,E,F,vis))
                return true;
                
          }
      }
      
      return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
   //  if(incircle(0, 0,D, E, F)) return "NO";
    
   
      vector<vector<bool>>vis(A+1,vector<bool>(B+1,false));
      return dfs(0,0,A,B,D,E,F,vis)==true?"YES":"NO";
    

    
}
