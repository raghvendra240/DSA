//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
      int mod = 1e9 + 7; 
      long long lastTwoSame[n];
      long long lastTwoDifferent[n];
      lastTwoSame[0] = 0;
      lastTwoDifferent[0] = k;

      for(int i = 1; i < n; i++) {
        lastTwoSame[i] = lastTwoDifferent[i-1];
        lastTwoDifferent[i] = ((lastTwoDifferent[i-1] + lastTwoSame[i-1]) * (k-1)) % mod;
      }

      return (lastTwoDifferent[n-1] + lastTwoSame[n-1]) % mod; 
  }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends