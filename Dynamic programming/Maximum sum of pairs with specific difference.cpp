link->https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference/0#





int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) 
{ 
    // Sort input array in ascending order. 
    sort(arr, arr+N); 
  
    // dp[i] denotes the maximum disjoint pair sum 
    // we can achieve using first i elements 
    int dp[N]; 
  
    //  if no element then dp value will be 0 
    dp[0] = 0; 
  
    for (int i = 1; i < N; i++) 
    { 
        
        dp[i] = dp[i-1];   not pairing with i-1th element
  
        // if current and previous element can form a pair 
        if (arr[i] - arr[i-1] < K) 
        { 
            // update dp[i] by choosing maximum between 
            // pairing and not pairing 
            if (i >= 2) 
                dp[i] = max(dp[i], dp[i-2] + arr[i] + arr[i-1]); //if(i>=2 then only we can access dp[i-2])
            else
                dp[i] = max(dp[i], arr[i] + arr[i-1]); 
        } 
    } 
  
    //  last index will have the result 
    return dp[N - 1]; 
} 
