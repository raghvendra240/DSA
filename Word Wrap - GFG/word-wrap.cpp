//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    vector<int>dp;
    int solve(int start, vector<int>&nums, int k) {
         int n = nums.size();
         if(start == n) {
             return 0;
         }
         if(dp[start] != -1) {
             return dp[start];
         }
         int res = INT_MAX;
         int total = 0;
        for(int i = start; i < n; i++) {
            total += nums[i];
            if(total > k) {
                break;
            }
            int freeSpace = i == nums.size() - 1 ? 0 : k - total;
            int otherLinesRes = solve(i+1, nums, k);
            res = min(res, otherLinesRes + (freeSpace * freeSpace));
            ++total; //for add betw
        }
        return dp[start] = res;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
       dp = vector<int>(nums.size(), -1);
       return solve(0, nums, k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends