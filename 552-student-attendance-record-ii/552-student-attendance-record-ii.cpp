class Solution {
    /*
    Let f[i][j][k] denote the # of valid sequences of length i where:

        There can be at most j A's in the entire sequence.
        There can be at most k trailing L's.
    */
public:
    int checkRecord(int n) {
       
     int M = 1e9 + 7;
        int dp[n + 1][2][3];
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                dp[0][j][k] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    int val = dp[i - 1][j][2];
                    if (j > 0) val = (val + dp[i - 1][j - 1][2]) % M;
                    if (k > 0) val = (val + dp[i - 1][j][k - 1]) % M;
                    dp[i][j][k] = val;
                }
            }
        }
        return dp[n][1][2];
    }
};