class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       unordered_map<int,int>count;
        int globalCount = 0;
        for (auto num : nums ) {
           globalCount += count[num];
            
            /* 
              count[num] countains all prev. num
              if a new num of same type is added then count[num] new pair will generated
            
            */
            count[num]++;
        }
        
        return globalCount;
    }
};