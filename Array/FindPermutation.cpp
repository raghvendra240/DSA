https://www.interviewbit.com/problems/find-permutation/

=====================================
When the input string contains only D or I we just need to return all positive number upto n either in descending or ascending orders respectively.
So if n = 3, s = “II”, return [1, 2, 3]

Now, starting with each character of the input string, we need to substitute an appropriate number(from 1 to n) corresponding to each character(I or D).


vector<int> Solution::findPerm(const string A, int B) {
    
    vector<int>nums(B);
    
    for(int i=0;i<B;i++)
      nums[i]=i+1;
     int i=0;
   while(i<A.length())
    {
        int j=i;
        while(A[j]=='D')
          {
             j++;
          }
          
        int low=i,high=j;
        
        while(low<high)
        {
            swap(nums[low++],nums[high--]);
        }
        i=j+1;
    }
    
    return nums;
}
