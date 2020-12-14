https://www.interviewbit.com/problems/sort-array-with-squares/

===================================================================

vector<int> Solution::solve(vector<int> &A) {
   int n=A.size();

        vector<int> ans(n,0);
       int i=0,j=n-1;
           int k=n-1;
           
  //i point at (largest number form when we do square of -ve numbers)
  //j--------------------------------------------------- +ve numbers
  while(i<=j)
  {
      //Kth posn is taken by the element which is greater among them
      
      if(abs(A[i])>abs(A[j]))
      {
          ans[k--]=A[i]*A[i];
          i++;
      }
      else
      {
          ans[k--]=A[j]*A[j];
          j--;
      }
  }
           
      return ans;

}
