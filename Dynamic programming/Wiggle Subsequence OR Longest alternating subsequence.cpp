link->https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence/0
      https://leetcode.com/problems/wiggle-subsequence/
      
      

//Use LIS and Include exclude strategy

use two array large[i]= LAS if subsequence end at i and  arr[i]>arr[j];
              small[i]= LAS if subsequence end at i and  arr[i]<arr[j];



class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>&arr=nums;
        int n=nums.size();
        if(n==0)
             return 0;
      int lar[n];
	     int small[n];
	     memset(lar,0,sizeof(lar));
	     memset(small,0,sizeof(small));
	     small[0]=1;
	     lar[0]=1;
	     int res=1;
	     for(int i=1;i<n;i++)
	     {
	         for(int j=0;j<i;j++)
	         {
	             if(arr[i]>arr[j])
	             {
	                 lar[i]=max(lar[i],small[j]+1);
	             }
	             else if(arr[i]<arr[j])
	             small[i]=max(small[i],lar[j]+1);
	         }
	         
	         res=max(res,max(lar[i],small[i]));
	     }
	 
	return res;   
    }
};
