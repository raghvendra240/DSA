
https://www.interviewbit.com/problems/longest-arithmetic-progression/

int Solution::solve(const vector<int> &A) {

   int n = A.size(), res = 2;
    if(n <= 2)
        return n;
    vector<unordered_map<int, int>> dp(n);  //(key, value) => (position, difference)
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = A[i] - A[j];
            dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
            res = max(res, dp[i][diff]);
        }
    }
    return res;
}
