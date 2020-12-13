link->https://www.interviewbit.com/problems/flip/

//use Kadan's algo
vector<int> Solution::flip(string A) {
    
    int n=A.length();
    vector<int>nums(n);
    
    for(int i=0;i<n;i++)
      {if(A[i]=='1')
           nums[i]=-1; 
                    
         else
          nums[i]=1;
      }
      
// 1->-1 not 0->-1 because we have to maximize no of ones . after flipping 
// no of 1s =(0s-1s) so we have to maximize 0s betwen L and R
      
      int res=0;
      pair<int,int>ans={INT_MAX,INT_MAX};
      
      int maxsofar=0;
      int start=0;
      for(int i=0;i<n;i++)
      {
          if(maxsofar+nums[i]<0)
             {
                 maxsofar=0;
                 start=i+1;
             }
            else
            {
                maxsofar+=nums[i];
            }
            
            if(maxsofar>res)
            {
                res=maxsofar;
                ans.first=start;
                ans.second=i;
                
            }
      }
      
      
      if(ans.first==INT_MAX)
         return {};
    
    return {ans.first+1,1+ans.second};
      
}
