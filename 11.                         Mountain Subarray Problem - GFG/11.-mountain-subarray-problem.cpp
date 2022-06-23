// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{
  public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q) {
        int N = n;
        int *arr =a;
        int left[n];
        int right[n];
         left[0] = 0;
    int lastIncr = 0;

    for (int i = 1; i < N; i++)
    {
        // if current value is greater than previous,
        // update last increasing
        if (arr[i] > arr[i - 1])
            lastIncr = i;
        left[i] = lastIncr;
    }

    // Initialize last right index as that index only
    right[N - 1] = N - 1;
    int firstDecr = N - 1;

    for (int i = N - 2; i >= 0; i--)
    {
        // if current value is greater than next,
        // update first decreasing
        if (arr[i] > arr[i + 1])
            firstDecr = i;
        right[i] = firstDecr;
    }

    vector<bool>res(q,false);
    for(int i= 0 ;i<q;i++){
        int L = queries[i].first;
        int R = queries[i].second;

        res[i] = (right[L] >= left[R]);
    }
    return res;

    }
};

// { Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}  // } Driver Code Ends