link->https://practice.geeksforgeeks.org/problems/special-keyboard3018/1

class Solution{
public:
    unsigned long long int optimalKeys(int N){
      
      unsigned long long int dp[N+1];
      
      if(N<6)
       return N;
      
      for(int i=0;i<=6;i++)
        dp[i]=i;
        
        for(int i=7;i<=N;i++)
        {
            dp[i]=i;
            
            for(int j=1;j<i-3;j++)
            {
                int p=(i-j-1);
                dp[i]=max(dp[i],dp[j]*p);
            }
        }
        
        return dp[N];
    }
};
