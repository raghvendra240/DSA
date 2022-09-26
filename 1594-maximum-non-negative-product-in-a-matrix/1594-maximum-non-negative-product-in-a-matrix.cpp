class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            long long dpMin[n][m];
            long long dpMax[n][m];

            dpMin[n-1][m-1] = dpMax[n-1][m-1] = grid[n-1][m-1];

            for (int j = m-2; j >= 0; --j) {
                dpMin[n-1][j] = dpMax[n-1][j] = grid[n-1][j] * dpMin[n-1][j+1];
            }
            for (int i = n-2; i >= 0; --i) {
                 dpMin[i][m-1] = dpMax[i][m-1] = grid[i][m-1] * dpMin[i+1][m-1];
            }

            for (int i = n-2; i >=0; --i) {
                for (int j = m-2; j>=0; --j) {

                    if (grid[i][j] > 0) {
                        dpMax[i][j] = grid[i][j] * max(dpMax[i][j+1], dpMax[i+1][j]);
                        dpMin[i][j] = grid[i][j] * min(dpMin[i][j+1], dpMin[i+1][j]);
                    } else {
                       dpMax[i][j] = grid[i][j] * min(dpMin[i][j+1], dpMin[i+1][j]);
                       dpMin[i][j] = grid[i][j] * max(dpMax[i][j+1], dpMax[i+1][j]);
                    }
                }
            }
           int mod = 1e9 +7 ;

            return dpMax[0][0] < 0 ? -1 : dpMax[0][0]%mod;
    }
};