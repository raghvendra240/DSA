
https://www.interviewbit.com/problems/maximum-sum-triplet/

int Solution::solve(vector<int> &A) {
    
    //using suffix array
    
    int n=A.size();
    int res=INT_MIN;
    
    vector<int>temp(n);
    
    temp[n-1]=A[n-1];
    
    for(int i=n-2;i>=0;i--)
      temp[i]=max(temp[i+1],A[i]);
      
      set<int> st;
      st.insert(A[0]);
for(int i=1; i<n-1; i++){
    st.insert(A[i]);
    if(A[i]>=temp[i+1]) 
       continue;
       
    auto it= st.find(A[i]);
    if(it==st.begin()) 
        continue;
    
    it--;
    res=max(res, (*it + A[i] + temp[i+1]));
}
    
   
    if(res==INT_MIN)
      return 0;
    return res;
}
