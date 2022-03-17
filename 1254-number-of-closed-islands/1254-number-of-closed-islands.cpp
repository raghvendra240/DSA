class Solution {
    int n;
    int m;
    // vector<vector<bool>>vis;
    bool help(int x,int y,vector<vector<int>>&grid){
        const int dx[] = {-1,1,0,0};
        const int dy[] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int r = x+dx[i];
            int c = y+dy[i];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size()){
                if(grid[r][c]==-1)
                    return false;
                if(grid[r][c]==0){
                    grid[r][c]=-2;
                    bool temp=help(r,c,grid);
                    if(!temp)
                        return false;
                }
            }
        }
        return true;
    }
     void fillBorder(int x,int y,vector<vector<int>>&grid){
        const int dx[] = {-1,1,0,0};
        const int dy[] = {0,0,-1,1};
        for(int i=0;i<4;i++){
            int r = x+dx[i];
            int c = y+dy[i];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size()&& grid[r][c]==0  ){
                grid[r][c]=-1;
                fillBorder(r,c,grid);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int res=0;
        m=grid[0].size();
        // vis.resize(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==0){
                        grid[i][j]=-1;
                        fillBorder(i,j,grid);
                    }
                }
            }
        }
         for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0){
                    grid[i][j]=-2;
                    res+=help(i,j,grid);
                }
            }
        }
        
        return res;
    }
};