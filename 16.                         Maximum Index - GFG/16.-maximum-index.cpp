// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    unordered_map<string,int>dp;
    int help(int *arr, int low, int high){
        if(low>high) return 0;
       string dpString = to_string(low) + "|"+to_string(high);
        if(dp.count(dpString)) return dp[dpString];
        if(arr[low] <= arr[high]) return high-low;
        return dp[dpString] = max(help(arr,low+1,high),help(arr,low,high-1));
    }
    int maxIndexDiff(int A[], int N) 
    { 
        
        return help(A,0 ,N-1);
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends