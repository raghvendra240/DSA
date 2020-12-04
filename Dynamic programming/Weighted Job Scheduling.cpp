link->https://leetcode.com/problems/maximum-profit-in-job-scheduling/

---O(n2) solution----

class Solution {
    class Tri
    {  
        public:
        
        int start;
        int end;
        int profit;
      
        Tri(int s,int e,int p)
        {
            start=s;
             end=e;
            profit=p;
        }
        
    };
    
    

 
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
       
        vector<Tri>nums;
        for(int i=0;i<profit.size();i++)
        {
            Tri temp(startTime[i],endTime[i],profit[i]);
            nums.push_back(temp);
            
        }
        
        sort(nums.begin(),nums.end(),[] (const auto &l, const auto &r) {return l.end<r.end;});
        
        int n=nums.size();
        int dp[n];
        int res=0;
        
        for(int i=0;i<n;i++)
        {    dp[i]=nums[i].profit;
           res=max(res,dp[i]);    
        }
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j].end<=nums[i].start)
                {
                    dp[i]=max(dp[i],dp[j]+nums[i].profit);
                }
            }
            res=max(res,dp[i]);
        }
        
        
        return res;
        
    }
};


------------------O(nlogn)------------------
//use binary search in inner loop

class Solution {
    class Tri
    {  
        public:
        
        int start;
        int end;
        int profit;
      
        Tri(int s,int e,int p)
        {
            start=s;
             end=e;
            profit=p;
        }
        
    };
    
    int binarySearch(vector<Tri>&jobs, int index) 
{ 
    // Initialize 'lo' and 'hi' for Binary Search 
    int lo = 0, hi = index - 1; 
  
    // Perform binary Search iteratively 
    while (lo <= hi) 
    { 
        int mid = (lo + hi) / 2; 
        if (jobs[mid].end <= jobs[index].start) 
        { 
            if (jobs[mid + 1].end <= jobs[index].start) 
                lo = mid + 1; 
            else
                return mid; 
        } 
        else
            hi = mid - 1; 
    } 
  
    return -1; 
} 
    
    

 
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
       
        vector<Tri>nums;
        for(int i=0;i<profit.size();i++)
        {
            Tri temp(startTime[i],endTime[i],profit[i]);
            nums.push_back(temp);
            
        }
        
        sort(nums.begin(),nums.end(),[] (const auto &l, const auto &r) {return l.end<r.end;});
        
        int n=nums.size();
        int dp[n];
        int res=0;
    
        dp[0]=nums[0].profit;
        res=dp[0];
        
        for(int i=1;i<n;i++)
        {
          
            int include=nums[i].profit;
            
            int x=binarySearch(nums,i);
            if(x!=-1)
                 include+=dp[x];
            
            dp[i]=max(include,dp[i-1]);
            res=max(res,dp[i]);
        }
        
        
        return res;
        
    }
};

