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
        
        /*
        Let's say the previous values are [x,y] and we now include current value i.e, z to it   
        as already covered subarrays till y in our ans, so only the new ones
        
        x,y,z
        y,z
        z,
        *****we can not add x,z [not subarray]

          so res= end-start+1
        */
        
        res+=(end-start+1);
    }
    return res;
}
};