//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    #include <climits>

    int optimalSearchTree(int keys[], int freq[], int n)
    {
        int dp[n][n];
        int freqPre[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                freqPre[i] = freq[i];
            } else {
                freqPre[i] = freqPre[i - 1] + freq[i];
            }
        }
        for (int gap = 0; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                if (gap == 0) {
                    dp[i][j] = freq[i];
                } else {
                    dp[i][j] = INT_MAX;
                    for (int k = i; k <= j; k++) {
                        int cost = freqPre[j] - (i > 0 ? freqPre[i - 1] : 0);
                        int left = k == i ? 0 : dp[i][k - 1];
                        int right = k == j ? 0 : dp[k + 1][j];
                        dp[i][j] = min(dp[i][j], left + right + cost);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }

};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends