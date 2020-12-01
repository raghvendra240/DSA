link->https://www.interviewbit.com/problems/merge-elements/

int dp[201][201];

int help(vector<int>&A,int low, int high)
{
    if(low==high)
      return 0;
   
   if(dp[low][high]!=-1)
     return dp[low][high];
     
   int sum=0;
   for(int i=low;i<=high;i++)
     sum+=A[i];
     
       int res=INT_MAX;
       for(int i=low;i<high;i++)
       {
           int above=help(A,i+1,high);
           int below=help(A,low,i);
           
           int temp= above+below+sum;
           
           res=min(res,temp);
           
       }
       
       return dp[low][high]=res;
}

int Solution::solve(vector<int> &A) {
    
    int n=A.size();
    
    if(n==1)
     return 0;
    memset(dp,-1,sizeof(dp));
      return help(A,0,n-1);
   
}
