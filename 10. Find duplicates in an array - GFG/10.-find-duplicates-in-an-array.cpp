// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>res;
        vector<int>temp(n,0);
        for(int i = 0 ;i<n;i++){
           temp[arr[i]]++;
        }
        for(int i = 0 ;i <n ;i++){
            if(temp[i] > 1){
                res.push_back(i);
            }
        }
        if(res.size() == 0) return  {-1};
        // return res.size() >0 ? res : {-1} ;
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends