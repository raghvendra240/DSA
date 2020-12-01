link->https://www.interviewbit.com/problems/egg-drop-problem/



//Using MCM and binary search

int dp[10001][101];
int help(int f,int egg)
{
    if(f==1)
      return 1;
      
     if(egg==1)
       return f;
       
       if(egg==0 || f==0)
         return 0;
        
        if(dp[f][egg]!=-1)
          return dp[f][egg];
        
        int ans=INT_MAX;
        int low=1;
        int high=f;
        while(low<=high)
        {
            int i=(low+high)/2;
            
            int above=dp[f-i][egg]==-1?help(f-i,egg):dp[f-i][egg];
            
            int below=dp[i-1][egg-1]==-1?help(i-1,egg-1):dp[i-1][egg-1];
            
            int res=max(above,below);
            ans=min(ans,res+1);
            
            if(above>below)
              low=i+1;
             
             else
              high=i-1;
        }
        
        return dp[f][egg]=ans;
      
}
 
int Solution::solve(int A, int B) {
    
    int e=A;
    int f=B;
    memset(dp,-1,sizeof(dp));
    return help(f,e);
}
