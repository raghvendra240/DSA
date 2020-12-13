void Solution::rotate(vector<vector<int> > &A) {
  
    
    int n=A.size();
    int m=A[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<m;j++)
        {
            swap(A[i][j],A[j][i]);
        }
    }
    
   
    for(int i=0;i<n;i++)
    {
        // int low=0;
        // int high=m-1;
        
        reverse(A[i].begin(),A[i].end()); //reverse rows for clockwise
        
        //reverse col for anti-clockwise
    }
    
    return;
}

