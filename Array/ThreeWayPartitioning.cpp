https://practice.geeksforgeeks.org/problems/three-way-partitioning/1


class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        vector<int>&nums=array;
        
        int i=0;
        int j=0;
        int k=nums.size()-1;
        while(j<=k)
        {
            if( nums[j]<a)
            {
            
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else if(nums[j]>b)
            {
               
                swap(nums[j],nums[k]);
                k--;
            }
            else
            j++;
            
        }
        
       
    }
};
