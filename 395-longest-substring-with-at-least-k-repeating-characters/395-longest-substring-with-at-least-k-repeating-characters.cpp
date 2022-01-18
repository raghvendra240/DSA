class Solution {
public:
    int longestSubstring(string s, int k) {
        //Check notes for logic
        int n=s.size();
        if(n==0 || n<k)
            return 0;
        if(k==1)
            return n;

        unordered_map<char,int>dp;
        for(char c : s)
            dp[c]++;
        int left=0;
        while(left < n && dp[s[left]]>=k)
            ++left;
        if(left>=n){
            return left;
        }

        int leftResult=longestSubstring(s.substr(0,left),k);

        while(left< n && dp[s[left]]<k)
            left++;
        int rightResult= left>=n ? 0   :longestSubstring(s.substr(left),k);

        return max(leftResult,rightResult);
    }
};