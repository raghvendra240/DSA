link->https://leetcode.com/problems/find-the-duplicate-number/submissions/


===================Using cycle sort================
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        vector<int>&arr=nums;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            while(arr[i]-1!=i && arr[i]!=arr[arr[i]-1])
            {
               
                swap(arr[i],arr[arr[i]-1]);
                
            }
         
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]-1!=i) 
                  return arr[i];
        }
        
        return 0;
        
    }
};

=======================================using array as Hashmap==================
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
       int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            nums[nums[i]%n]=nums[nums[i]%n]+n;
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>2*n)
                 return i;
        }
        
        return 0;
    }
};
