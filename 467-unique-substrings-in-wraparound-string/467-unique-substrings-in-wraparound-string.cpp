class Solution {
public:
    int findSubstringInWraproundString(string p) {
     
        vector<int>count(26,0);
        int len = 0;
        for(int i = 0; i < p.length(); ++i) {
            if(i > 0 && ((p[i-1] == 'z' && p[i] == 'a') || p[i-1]+1 == p[i] )) {
                ++len;
            } else {
                len = 1;
            }
            
            count[p[i]-'a'] = max(len, count[p[i]-'a']);
            
        }
        int res = 0;
        for(auto val : count) {
            res += val;
        }
        return res;
    }
};