https://www.interviewbit.com/problems/coin-sum-infinite/



int Solution::coinchange2(vector<int> &A, int B) {


vector<int>&S=A;
int n=B;
int m=A.size();

     int table[n+1]; 
  
    // Initialize all table values as 0 
    memset(table, 0, sizeof(table)); 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n];
}
