class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>dp;
        string copy;
        for(auto s : strs){
            copy=s;
            sort(s.begin(),s.end());
            dp[s].push_back(copy);
        }
        vector<vector<string>>res;
        for(auto val : dp)
            res.push_back(val.second);
        return res;
    }
};