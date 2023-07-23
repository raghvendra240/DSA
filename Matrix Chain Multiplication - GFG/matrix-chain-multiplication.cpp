//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];
        for(int gap = 0; gap < N; ++gap) {
            for(int i = 0, j = gap; j < N ; i++, j++) {
                dp[i][j] = INT_MAX;
                if(gap == 0) {
                    dp[i][j] = 0;
                }else if(gap == 1) {
                    dp[i][j] = arr[i-1] * arr[i] * arr[j];
                }else {
                    for(int k = i; k < j; k++) {
                        int tempRes = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                        dp[i][j] = min(dp[i][j], tempRes);
                    }
                }
            }
        }
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends