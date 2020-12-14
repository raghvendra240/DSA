https://www.interviewbit.com/problems/maximum-unsorted-subarray/


vector<int> Solution::subUnsort(vector<int> &A) {
    
    int n=A.size();
    int i=0;
    
    while(i<n-1 && A[i]<=A[i+1])
      i++;
      
      int j=n-1;
      while(j>0 && A[j]>=A[j-1])
         j--;
         
         
         if(i>=j)
           return {-1};
           
           int mini=INT_MAX;
           int maxi=INT_MIN;
           
           for(int k=i;k<=j;k++)
           {
               mini=min(mini,A[k]);
               maxi=max(maxi,A[k]);
               
           }
           
           for(int k=0;k<i;k++)
           {
               if(A[k]>mini)
                 {
                     i=k;
                     break;
                 }
           }
           
           
           for(int k=n-1;k>j;k--)
           {
               if(A[k]<maxi)
               {
                   j=k;
                   break;
               }
           }
       
        return {i,j};
}
