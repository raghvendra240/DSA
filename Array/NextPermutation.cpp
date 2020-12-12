link->https://leetcode.com/problems/next-permutation/submissions/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
       int index=-1;
        
        for(int i=n-1;i>0;i--)
        {
           if(nums[i-1]<nums[i])
           {
               index=i-1;
               break;
           }
        }
        
       if(index==-1)
       {
           sort(nums.begin(),nums.end());
           return;
       }
        int second=index+1;
        int ans=nums[second];
        int j=index+2;
        while(j<n)
        {
            if(nums[j]>nums[index] && nums[j]<ans)
            {
                ans=nums[second];
                second=j;
            }
            j++;
        }
        
        swap(nums[index],nums[second]);
        sort(nums.begin()+index+1,nums.end());
        return;
        
    }
};
