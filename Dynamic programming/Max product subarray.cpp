link-->https://www.interviewbit.com/problems/max-sum-contiguous-subarray/

//just like kadane algo for max subaaray sum
int Solution::maxProduct(const vector<int> &A) {

    int n=A.size();
    int res,
    minTillHere,
    maxTillHere;
    res=minTillHere=maxTillHere=A[0];

    for(int i=1;i<n;i++)
    {
     

      int p1=maxTillHere*A[i];
      int p2=minTillHere*A[i];

      maxTillHere=max(max(p1,p2),A[i]);
      minTillHere=min(min(p1,p2),A[i]);

      res=max(res,maxTillHere);
    }

    return res;
}


