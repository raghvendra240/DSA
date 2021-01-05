link->https://www.interviewbit.com/problems/permutation-swaps/

//find connected components assuming indexs as the nodes;
//Now two nodes can only be swaped if they are in same componenet

int find(int x ,vector<int>&par)
{
    if(par[x]==-1)
      return x;
      
      return par[x]=find(par[x],par);
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
  
     int n=A.size();
     vector<int>parent(n+1,-1);
 
   for(int i=0;i<C.size();i++)
   {
       int left=C[i][0]-1;
       int right=C[i][1]-1;
       
       int a=find(A[left],parent);
       int b=find(A[right],parent);
       
       if(a!=b)
        return parent[a]=b;
   
   }
   
   for(int i=0;i<A.size();i++)
   {
       if(A[i]!=B[i])
         {
             int a=find(A[i],parent);
             int b=find(B[i],parent);
             
             if(a!=b)
               return 0;
         }
   }
   
   return 1;
}
