link->https://www.interviewbit.com/problems/max-distance/


int Solution::maximumGap(const vector<int> &A) {
    
       int n = A.size();
    vector<pair<int,int>> v;
    if(n == 0) return -1;
    for(int i=0;i<n;i++) {
        v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    
    //using algo to find max difference betwen two element
    
    int min_ind = v[0].second,ans = 0;
    for(int i=1;i<n;i++) {
        min_ind = min(min_ind,v[i].second);
        ans = max(ans, v[i].second - min_ind);
    }
    return ans;
    
    
}
