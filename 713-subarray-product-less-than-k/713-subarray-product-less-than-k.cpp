class Solution {
public:
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
   
    int res=0;     
    int p=1;
    int start=0;
    for(int end=0;end<nums.size();end++){
        p*=nums[end];
        while(start<=end && p>=k){
            p/=nums[start++];
        }
        
        res+=(end-start+1);
    }
    return res;
}
};