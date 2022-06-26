class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 0 ;i < n ; i++){
            int j = i -1 ;
            while(j>=0 && arr[j] < arr[j+1]) --j;
            if(abs(i-j) < 2) continue;
            int k = i+1;
            while(k<n && arr[k] < arr[k-1]) k++;
           if(abs(i-k) < 2 ) continue;
            res = max(res, k-j-1);
        }
        return res<3 ? 0 : res;
        
    }
};