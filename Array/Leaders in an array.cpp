https://www.interviewbit.com/problems/leaders-in-an-array/

vector<int> Solution::solve(vector<int> &A) {
    int n=A.size();
    
    vector<int>nums(n);
    nums[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--)
    {
        nums[i]=max(A[i],nums[i+1]);
    }
    
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==A[i]);
          res.push_back(nums[i]);
    }
    
    return res;
}
