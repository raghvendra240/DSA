link->https://www.interviewbit.com/problems/tiling-with-dominoes/

      https://www.geeksforgeeks.org/tiling-with-dominoes/




int help(int n)
{
    long int A[n + 1], B[n + 1]; 
    A[0] = 1, A[1] = 0, B[0] = 0, B[1] = 1; 
    for (int i = 2; i <= n; i++) { 
        A[i] = (A[i - 2] + 2 * B[i - 1])%1000000007; 
        B[i] =( A[i - 1] + B[i - 2])%1000000007; 
    } 

    return A[n];

}
int Solution::solve(int A) {
    
    if(A%2!=0)
      return 0;

  return help(A);
}
