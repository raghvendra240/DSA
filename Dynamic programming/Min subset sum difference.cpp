
link->https://www.interviewbit.com/problems/minimum-difference-subsets/

int Solution::solve(vector<int> &A) {
    
      int n=A.size();
    int B=0;
    for(int x:A)
     B+=x;
     
    int dp[n+1][B+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=n;i++)
     dp[i][0]=1;
     int res=INT_MIN;
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=B;j++)
         {
             dp[i][j]=dp[i-1][j];
             
             if(A[i-1]<=j)
              dp[i][j]|=(dp[i-1][j-A[i-1]]);
              
               if(i==n && dp[i][j]==1)
            {
                  if(j<=(B/2))
                    res=max(res,j);
             }
         }
         
        
     }
     
     return B-(2*res);
}
