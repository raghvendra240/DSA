class Solution {
        void help(int x,int y,vector<vector<char>>&grid){
        const int dx[] = {-1,1,0,0};
        const int dy[] = {0,0,-1,1};
        
        for(int i=0;i<4;i++){
            int r = x+dx[i];
            int c = y+dy[i];
            if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size()&& grid[r][c]=='1'){
                grid[r][c]='0';
                help(r,c,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1')
                {
                    ++res;
                    grid[i][j]='0';
                    help(i,j,grid);
                }
            }
        }
        return res;
    }
};