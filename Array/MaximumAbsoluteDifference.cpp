https://www.interviewbit.com/problems/maximum-absolute-difference/


Case 1: A[i] > A[j] and i > j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = i - j
hence, f(i, j) = (A[i] + i) - (A[j] + j)

Case 2: A[i] < A[j] and i < j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = -(i) + j
hence, f(i, j) = -(A[i] + i) + (A[j] + j)

Case 3: A[i] > A[j] and i < j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = -(i) + j
hence, f(i, j) = (A[i] - i) - (A[j] - j)

Case 4: A[i] < A[j] and i > j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = i - j
hence, f(i, j) = -(A[i] - i) + (A[j] - j)




We have to find the absolute value of f(i,j). Case 1 &4 and Case2&3 are similar if we have to find the absolute value. Now suppose there are only two cases that is 1 and 2.
Consider Case 1 –
To maximize f(i, j) we have to find the diff between the max and min value. Max value of A[i]+i and min value of A[j]+j. Lets suppose the difference is d1

Consider Case 2 –
To maximize f(i, j) we have to find the diff between the max and min value. Max value of A[i]-i and min value of A[j]-j. Lets suppose the difference is d2
and now we have to find the max value of d1 and d2.






int Solution::maxArr(vector<int> &A) {

    int n=A.size();
     int max1 = INT_MIN, min1 = INT_MAX; 
    int max2 = INT_MIN, min2 = INT_MAX; 
  
    for (int i = 0; i < n; i++) { 
  
        // Updating max and min variables 
        // as described in algorithm. 
        max1 = max(max1, A[i] + i); 
        min1 = min(min1, A[i] + i); 
        max2 = max(max2, A[i] - i); 
        min2 = min(min2, A[i] - i); 
    } 
  
    // Calculating maximum absolute difference. 
    return max(max1 - min1, max2 - min2); 
}
