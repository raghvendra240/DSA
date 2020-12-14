https://www.interviewbit.com/problems/pick-from-both-sides/


int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int>suff(n);
    
    suff[n-1]=A[n-1];
    
    for(int i=n-2;i>=0;i--)
      suff[i]=A[i]+suff[i+1];
      
     int sum=0;
     int res=INT_MIN;
     for(int i=0;i<=B;i++)
     {
         sum+=A[i];
         int temp= i>0?sum:0 +(suff[n-1-B+i]);
         res=max(res,temp);
     }
     
     return res;
}
