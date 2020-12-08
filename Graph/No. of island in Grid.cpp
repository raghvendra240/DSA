link->https://www.interviewbit.com/problems/black-shapes/

int row[]={0,0,-1,1};
int col[]={-1,1,0,0};

void dfs(int x,int y,vector<string> &A,vector<vector<bool>>&vis)
{
    vis[x][y]=true;
    
    for(int i=0;i<4;i++)
    {
        int r=row[i]+x;
        int c=col[i]+y;
        
        if(r>=0 && c>=0 && r<A.size() && c<A[0].size() && vis[r][c]==false && A[r][c]=='X')
        {
            dfs(r,c,A,vis);
        }
    }
}

int Solution::black(vector<string> &A) {
    
    int n=A.size();
    int m=A[0].size();
    
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==false && A[i][j]=='X')
            {
                dfs(i,j,A,vis);
                count++;
            }
            
        }
    }
    
    return count;
}
