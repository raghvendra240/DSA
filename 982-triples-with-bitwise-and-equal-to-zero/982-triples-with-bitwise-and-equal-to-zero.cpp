class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int>&A=nums;
        unordered_map<int,int> mp;
        for(auto a:A){
            for(auto b:A){
                mp[a&b]++;
            }
        }
        int res=0;
        for(auto a:A){
            for(auto t:mp){
                if((a&t.first)==0){
                    res+=t.second;
                }
            }
        }
        return res;
    }
};