link->https://www.interviewbit.com/problems/subset-sum-problem/

int Solution::solve(vector<int> &A, int B) {
    
    int n=A.size();
    
    int dp[n+1][B+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=n;i++)
     dp[i][0]=1;
     
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=B;j++)
         {
             dp[i][j]=dp[i-1][j];
             
             if(A[i-1]<=j)
              dp[i][j]|=(dp[i-1][j-A[i-1]]);
         }
     }
     
     return dp[n][B];
}
