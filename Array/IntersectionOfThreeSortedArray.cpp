
link->https://practice.geeksforgeeks.org/problems/common-elements1132/1#

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            int maxi=max(A[i],max(B[j],C[k]));
          //  vector<int>res;
           set<int>s;
            
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && A[i]==C[k])
                   {
                      s.insert(A[i]);
                       i++;
                       j++;
                       k++;
                   }
                   
                   else
                   {
                       while(A[i]<maxi)
                        i++;
                        
                        while(B[j]<maxi)
                         j++;
                         
                         while(C[k]<maxi)
                          k++;
                   }
                   
                   
                   maxi=max(A[i],max(B[j],C[k]));
                   
                   

            }
         return vector<int>(s.begin(),s.end());
        }
        

        

};
