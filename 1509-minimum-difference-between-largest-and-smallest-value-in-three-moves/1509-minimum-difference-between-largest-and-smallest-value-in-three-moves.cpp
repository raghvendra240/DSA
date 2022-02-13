class Solution {
    int help(int chance , vector<int>&nums,int low,int high){
        
        if(low>high)
            return 0;
        if(chance==0){
            return (nums[high]-nums[low]);
        }
        
        return min(help(chance-1,nums,low+1,high),help(chance-1,nums,low,high-1));
    }
public:
    int minDifference(vector<int>& nums) {
      //   if(nums.size()<=3)
      //       return 0;
        sort(nums.begin(),nums.end());
      // int ans1=abs(nums[0]-nums[nums.size()-4]);
      // int ans2=abs(nums[3]-nums[nums.size()-1]);
      // return min(ans1,ans2);
        
        return help(3,nums,0,nums.size()-1);
        
    }
};