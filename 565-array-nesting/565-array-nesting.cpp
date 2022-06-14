class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<bool>vis(n,false);
        int res = 0;
        for(int i =0 ;i < n ; ++i){
            int k = i;
            int len = 1;
            vis.resize(n,false);
            vis[k] = true;
            while(k < n && nums[k] < n && nums[k] != nums[nums[k]]){
                k = nums[k];
                if(vis[k]) break;
                vis[k] = true;
                ++len;
                if(len ==n ) break;
            }
            res = max(res, len);
        }
        return res;
    }
};