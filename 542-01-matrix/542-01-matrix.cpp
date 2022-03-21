class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>>&grid=mat;
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>res(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    q.push({i,j});
            }
        }  

        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        while(q.empty()==false)
        {
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            vis[x][y]=true;
           for(int i=0;i<4;i++)
            {
                 int newR=x+row[i];
                 int newC=y+col[i];

                 if(newC>=0 && newR>=0 && newC<m && newR<n && vis[newR][newC]==false && grid[newR][newC]==1)
                 {
                    int newDist= res[x][y]+1;
                    res[newR][newC]=newDist;
                    vis[newR][newC]=true;
                    q.push({newR,newC});
                 }
            }

        }

        return res;


    }
};