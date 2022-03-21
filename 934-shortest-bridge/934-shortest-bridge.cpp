class Solution {
    
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    
    void fill(vector<vector<int>>&A,int x,int y,queue<pair<int,pair<int,int>>>&q)
    {
        A[x][y]=2;
        q.push({x,{y,0}});
        for(int i=0;i<4;i++)
        {
            int r=row[i]+x;
            int c=col[i]+y;
            
            if(r>=0 && r<A.size() && c>=0 && c<A[0].size() && A[r][c]==1)
                  fill(A,r,c,q);
        }
    }
    
public:
    int shortestBridge(vector<vector<int>>& A) {
        
        int n=A.size();
        int m=A[0].size();
        queue<pair<int,pair<int,int>>>q;
        bool found=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(A[i][j])
                {
                    found=true;
                    fill(A,i,j,q);
                    break;
                }
            }
            
            if(found)
                break;
        }
        
        vector<vector<bool>>vis(A.size(),vector<bool>(A[0].size(),false));
        while(q.empty()==false)
        {
            auto temp=q.front();
            q.pop();
            
            int x=temp.first;
            int y=temp.second.first;
            int d=temp.second.second;
            vis[x][y]=true;
            
            if(A[x][y]==1)
                 return d-1;
            
             for(int i=0;i<4;i++)
        {
            int r=row[i]+x;
            int c=col[i]+y;
            
            if(r>=0 && r<A.size() && c>=0 && c<A[0].size() && vis[r][c]==false)
                { 
                vis[r][c]=true;
                
                // if(A[r][c])
                //       return d;
                q.push({r,{c,d+1}});
            }
        }
            
        }
        
        return -1;
        
        
    }
};