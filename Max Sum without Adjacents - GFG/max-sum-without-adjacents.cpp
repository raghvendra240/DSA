// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
unordered_map<string,int>dp;
// int dp[100][100];
int help(int low,int high,int *nums){
	if(low>high) return 0;
	if(low==high) return nums[low];
	string dpStr = to_string(low)+"|"+to_string(high);
	if(dp.count(dpStr)) return dp[dpStr];
	return dp[dpStr] = max(help(low+1,high,nums),nums[low]+help(low+2,high,nums));
}
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   // memset(dp,-1,sizeof(dp));
	   //return help(0,n-1,arr);
	   int dp[n+1] ={0};
	   dp[1]=arr[0];
	   for(int i= 2 ;i <=n ;i++){
	       dp[i] =max(dp[i-1],dp[i-2]+arr[i-1]);
	   }
	   return dp[n];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends