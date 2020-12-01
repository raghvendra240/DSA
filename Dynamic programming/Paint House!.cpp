link->https://www.interviewbit.com/problems/paint-house/


int Solution::solve(vector<vector<int> > &A) {
    
    int n=A.size();
    int dp[3][n];
    
    //0->red 1->blue 2->green
    
    dp[0][0]=A[0][0];
    dp[1][0]=A[1][0];
    dp[2][0]=A[2][0];
    
    for(int i=1;i<n;i++)
    {
        dp[0][i]= A[0][i]+ min(dp[1][i-1],dp[2][i-1]);
        dp[1][i]= A[1][i]+ min(dp[0][i-1],dp[2][i-1]);
        dp[2][i]= A[2][i]+ min(dp[1][i-1],dp[0][i-1]);
        
    }
    
    
    return min(dp[0][n-1],min(dp[1][n-1],dp[2][n-1]));
    
}
