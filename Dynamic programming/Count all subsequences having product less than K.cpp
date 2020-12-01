link-->https://www.geeksforgeeks.org/count-subsequences-product-less-k/


Recursive

#include<bits/stdc++.h>
using namespace std;
//initially pass 1 as prev
int help(vector<int>&nums,int prev,int index,int k)
{
  if(index<0)
      return 0;


int res=0;

  res+=help(nums,prev,index-1,k);  //we not considering current element
  if(nums[index]*prev<k)  //we can only consider curr elem. if this conditon satisfy
    {
           res+=help(nums,nums[index]*prev,index-1,k)+1;
    }

    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
      cin>>nums[i];

      int k;
      cin>>k;

  
      cout<<help(nums,1,n-1,k);

}

--------------------------------------------------------------------------
Bottom Up

int productSubSeqCount(vector<int> &arr, int k) 
{ 
    int n = arr.size(); 
    int dp[k + 1][n + 1]; 
    memset(dp, 0, sizeof(dp)); 
  
    for (int i = 1; i <= k; i++) { 
        for (int j = 1; j <= n; j++) { 
     
            // number of subsequence using j-1 terms 
            dp[i][j] = dp[i][j - 1]; 
    
            // if arr[j-1] > i it will surely make product greater 
            // thus it won't contribute then 
            if (arr[j - 1] <= i && arr[j - 1] > 0) 
  
                // number of subsequence using 1 to j-1 terms 
                // and j-th term 
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1; 
        } 
    } 
    return dp[k][n]; 
} 
