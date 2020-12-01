link-->https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

int zeroes(int arr[], int n)      //This simple count no of subarray with sum=0 in 1D array
{
   unordered_map<int, int> mp;
   int count = 0;
   int sum = 0;
   for(int i = 0; i < n; i++)
   {
      sum += arr[i];
      if(sum==0)
      {
          count++;
      }
      if(mp.find(sum) != mp.end())
      {
          count += mp[sum];
      }
      mp[sum]++;
  }
  return count;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    if(n==0 || m==0)
    {
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < m; i++)        //our submatrix start with ith col.
    {
        int arr[n] = {0};                 
        for(int j = i; j < m; j++)    //col of submatrix = [j....i]
        {
            for(int k = 0; k < n; k++)   
            {
                arr[k] = arr[k] + A[k][j];
            }
                    ans = ans + zeroes(arr,n);
        }
    }
    return ans;
}
