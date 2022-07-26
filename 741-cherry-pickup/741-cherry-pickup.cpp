class Solution {
    int n;
    int help(int i1,int j1,int i2,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp) {
        
        if(i1 >= n || j1>=n || i2>=n || j2>=n|| grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e9;
        
        if(i1 == n-1 && i2 == n-1 && j1 == n-1 && j2 == n-1){
            return grid[n-1][n-1];
        }
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];

        int res = -1e9;
        int cherries = (i1 == i2 && j1 == j2) ? grid[i1][j1] : grid[i1][j1] + grid[i2][j2];
        res = max(res, help(i1+1,j1,i2+1,j2,grid, dp) + cherries );
        res = max(res, help(i1,j1+1,i2,j2+1,grid, dp) + cherries );
        res = max(res, help(i1,j1+1,i2+1,j2,grid, dp) + cherries );
        res = max(res, help(i1+1,j1,i2,j2+1,grid, dp) + cherries );

        return dp[i1][j1][i2] = res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
            n = grid.size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
            return max(help(0,0,0,0,grid,dp),0);
    }
};