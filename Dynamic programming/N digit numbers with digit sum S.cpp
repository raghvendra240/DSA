Problem link -> https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/


long int dp[1001][1001];

long int help(int index,int n,int sum)
{
    if(sum<0 || (index==n+1 && sum>0 )|| (index==n && sum>9))
       return 0;
     
     if((index==n+1 && sum==0) || (index==n && sum<=9))
       return dp[index][sum]=1;
       
       if(dp[index][sum]!=-1)
          return dp[index][sum];
      
      long int res=0;  //contains result
      int start=0;    
      if(index==1)
         start=1;  //if index is at first digit then we can not start from 0
    
    for(;start<=9;start++)
    {
        res=(res+help(index+1,n,sum-start))%1000000007;
    }
    
    return dp[index][sum]=res;
         
}

int Solution::solve(int A, int B) {
    
    memset(dp,-1,sizeof(dp));
    return help(1,A,B);  //here 1 represent the pos of digit
}



