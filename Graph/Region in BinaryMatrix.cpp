link->https://www.interviewbit.com/problems/region-in-binarymatrix/


int row[8]={0, 1, 1, 1, 0, -1, -1, -1};
int col[8]={1, 1, 0, -1, -1, -1, 0, 1};

bool safe(int x,int y,vector<vector<int>>&A,vector<vector<bool>>&vis)
{
     int n=A.size();
    int m=A[0].size();
    
    if(x<0 || x>=n || y<0 || y>=m)
      return false;
      
      if(vis[x][y] || A[x][y]==0)
         return false;
         
         return true;
}

int dfs(int x,int y,vector<vector<int>>&A,vector<vector<bool>>&vis)
{
    vis[x][y]=true;
    int res=0;
    for(int i=0;i<8;i++)
    {
        int r=row[i]+x;
        int c=col[i]+y;
        
        if(safe(r,c,A,vis))
        {
           res+= dfs(r,c,A,vis)+1;
        }
    }
    
    return res;
}


int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int res=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j] && vis[i][j]==false)
            {
                int temp=1+dfs(i,j,A,vis);
                res=max(res,temp);
            }
        }
    }
    
    return res;
    
}
