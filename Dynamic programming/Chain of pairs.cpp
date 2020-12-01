Link->https://www.interviewbit.com/problems/chain-of-pairs/

//Using LIST
int Solution::solve(vector<vector<int> > &A) {
    
    int res=0;
    int n=A.size();
    vector<int>dp(n);  //stores length
    vector<int>help(n); //stores last element of chain till ith index
    dp[0]=1;
    help[0]=A[0][1];
    res=1;
    
    for(int i=1;i<n;i++)
    {
        int x=A[i][0];
        dp[i]=1;
        help[i]=A[i][1];
        for(int j=0;j<i;j++)
        {
            if(x>help[j])
            {
                if(dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        
        res=max(res,dp[i]);
    }
    
    return res;
}
