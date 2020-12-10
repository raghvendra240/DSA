link->https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

void dfs(int x,int y,int N,int m[MAX][MAX],vector<string>&res,string temp,vector<vector<bool>>&vis)
{
    if(x<0|| y<0 || x>=N || y>=N || m[x][y]==0 || vis[x][y]==true )
      return;
    
    
    if(x==N-1 && y==N-1)
    {
        res.push_back(temp);
        return;
    }
    int n=N;
    
    vis[x][y]=true;
    
    //use this order to produce sorted result O.W. we need to sort res array
    
    dfs(x+1,y,n,m,res,temp+'D',vis);
    dfs(x,y-1,n,m,res,temp+'L',vis);
    dfs(x,y+1,n,m,res,temp+'R',vis);
    dfs(x-1,y,n,m,res,temp+'U',vis);
    
    vis[x][y]=false;
    
    
}

vector<string> printPath(int m[MAX][MAX], int n) {
    
    if(m[0][0]==0)
       return {};
    
   vector<string>res;
   string temp="";
 
   vector<vector<bool>>vis(n,vector<bool>(n,false));
   dfs(0,0,n,m,res,temp,vis);
   
   return res;
}
