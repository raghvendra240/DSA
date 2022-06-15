// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        queue<int>q;
        for(int i = 0 ; i< n ; i++ ){
          if(a[i] == x) q.push(i);
        }
    int res = -1;
    while(q.empty() == false){
    
      int k = q.size();
      res++;
      while(k--){
        int index = q.front();
        q.pop();
        if(a[index] == y ){
          return res;
        }
        a[index] = -1;
        if(index-1>=0 &&  a[index-1] != -1){
            q.push(index-1);
        }
        if(index+1 < n && a[index+1] != -1){
         q.push(index +1);
        }
        
      }
    }
     return -1;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends