https://practice.geeksforgeeks.org/problems/cutted-segments1642/1#


Bottom up


int maximizeTheCuts(int n, int x, int y, int z)
{
   
    int dp[n+1];
    dp[0]=0;
    
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        if(i-x>=0)
          dp[i]=max(dp[i],dp[i-x]);
          
          if(i-y>=0)
          dp[i]=max(dp[i],dp[i-y]);
          if(i-z>=0)
          dp[i]=max(dp[i],dp[i-z]);
          
          if(dp[i]!=-1)
           dp[i]++;
    }
    
    return dp[n]==-1?0:dp[n];
    
}


---------------------------------------------------------------------
Top down

int maximizeTheCuts(int n, int x, int y, int z)
{
    // memset(dp,-1,sizeof(dp));
    // int arr[]={x,y,z};
    // int ans=help(n,arr);
    // // if(ans==INT_MIN+1)
    // //   return 0;
      
    //   return ans;
    
    int dp[n+1];
    dp[0]=0;
    
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        if(i-x>=0)
          dp[i]=max(dp[i],dp[i-x]);
          
          if(i-y>=0)
          dp[i]=max(dp[i],dp[i-y]);
          if(i-z>=0)
          dp[i]=max(dp[i],dp[i-z]);
          
          if(dp[i]!=-1)
           dp[i]++;
    }
    
    return dp[n]==-1?0:dp[n];
    //Your code here
}
