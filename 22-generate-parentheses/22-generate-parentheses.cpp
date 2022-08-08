class Solution {
    vector<string>res;
    void help(int open, int close, int n, string tempRes) {
        if(open == n && close == n){
            res.push_back(tempRes);
            return;
        }
        if(open < n){
            help(open+1,close,n,tempRes+'(');
        }
        if( open > close) {
            help(open,close+1,n,tempRes+')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        help(0,0,n,"");
        return res;
    }
};