Link->https://www.interviewbit.com/problems/knight-on-chess-board/



//The index is 1Based

int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 

struct tri
{
    int x,y,wt;
};
  

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    
    vector<vector<bool>>vis(A+1,vector<bool>(B+1,false));
   
    queue<tri>q;
    q.push({C,D,0});
    vis[C][D]=true;
    
    while(q.empty()==false)
    {
        
        auto[x,y,step]=q.front();
        q.pop();
        
        if(x==E && y==F)
          return step;
       
          for(int i=0;i<8;i++)
          {
              int row=dx[i]+x;
              int col=dy[i]+y;
              
              if(row>=1 && row<=A && col>=1 && col<=B && vis[row][col]==false)
                  {
                      if(row==E && col==F)
                        return step+1;
                      q.push({row,col,step+1});
                      vis[row][col]=true;
                  }
              
          }
          
    }
    
    return -1;
      
    
}
