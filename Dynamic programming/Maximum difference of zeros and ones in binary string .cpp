link->https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1#

//Make a new array ans consider 0->1 ans 1->-1 ans find max sum using KADANS ALGO

class Solution{
    
    bool allOne(string &s)
    {
        int temp=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
              temp++;
        }
        
        return temp==s.size();
    }
public:	
	int maxSubstring(string S)
	{
	    if(allOne(S))
	       return -1;
	       
      int n=S.size();
      int nums[n];
      for(int i=0;i<n;i++)
       nums[i]=S[i]=='1'?-1:1;   
       
       
       int res=nums[0];
       int prev=nums[0];
       
       for(int i=1;i<n;i++)
       {
           prev=max(prev+nums[i],nums[i]);
           res=max(res,prev);
       }
       
       return res;
	}
};
