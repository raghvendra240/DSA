https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>>res;
        
        if(intervals.size()==0)
             return res;
        int n=intervals.size();
        res.push_back(intervals[0]);
        int index=0;
        
        for(int i=1;i<n;i++)
        {
            if(res[index][1] >= intervals[i][0])
            {
                int x= min(res[index][0],intervals[i][0]);
                int y=max(res[index][1],intervals[i][1]);
                
                res[index][0]=x;
                res[index][1]=y;
                
            }
            
            else
            {
                res.push_back(intervals[i]);
                index++;
            }
        }
        
    return res;
        
    }
};
