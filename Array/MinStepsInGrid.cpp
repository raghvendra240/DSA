https://www.interviewbit.com/problems/min-steps-in-infinite-grid/


int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
int i,sum=0;
for(i=0;i<A.size()-1;i++)
{
sum+=max(abs(A[i]-A[i+1]),abs(B[i]-B[i+1]));
}
return sum;
}
