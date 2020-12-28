
https://leetcode.com/problems/longest-valid-parentheses/
========DP based approach====
class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        if(n==0)
             return 0;
     int dp[n];
        memset(dp,0,sizeof(dp));
        int res=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')
                {
                    int index=max(i-2,0);
                    dp[i]=dp[index]+2;
                }
                else
                {
                    int index= i-dp[i-1]-1;
                    if(index<0)
                         continue;
                    if(s[index]=='(')
                   {
                        int index=max(i-dp[i-1]-2,0);
                    dp[i]= dp[i-1]+ dp[index]+2;}
                    
                }
            }
            
            res=max(res,dp[i]);
        }
        return res;
    }
};

=================Stack based approch

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> my_stack;
        my_stack.push(-1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                my_stack.push(i);
            } else {
                my_stack.pop();
                if (my_stack.empty()) {
                    my_stack.push(i);
                } else {
                    ans = max(ans, i - my_stack.top());
                }
            }
        }
        return ans;
    }
};
