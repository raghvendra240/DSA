link->https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/


||Top_down||


int dp[20001];
int help(int index,vector<vector<int>>&A)
{
    if(index>=A[0].size())
      return 0;
      
      if(dp[index]!=-1)
        return dp[index];
       int exfirst=help(index+1,A);
      int exsec=help(index+1,A);
      
      int first= A[0][index] + help(index+2,A);
      int sec= A[1][index] +help(index+2,A);
      
     return dp[index]=max(first,max(sec,max(exfirst,exsec)));
}
 
 
int Solution::adjacent(vector<vector<int> > &A) {
 
memset(dp,-1,sizeof(dp));
  return help(0,A);
 
    
   
}



-------------------------------------------------
||Bottom Up||

int Solution::adjacent(vector<vector<int> > &A) {

  int n=A[0].size();
  int maxInPrevCol=max(A[0][0],A[1][0]);
   vector<vector<int>>dp(2,vector<int>(n));
   dp[0][0]=maxInPrevCol;
   dp[1][0]=0;

  for(int i=1;i<n;i++)
  {
     maxInPrevCol=max(A[0][i],A[1][i]);
    
    dp[0][i]= maxInPrevCol + dp[1][i-1];
    dp[1][i]=max(dp[0][i-1],dp[1][i-1]);
      
  }

  return max(dp[0][n-1],dp[1][n-1]);

    
   
}
