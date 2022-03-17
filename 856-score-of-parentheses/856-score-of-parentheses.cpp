class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int open=0;
        int close=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                ++open;
            else ++close;
            
            if(open==close){
                    int inner=1;
                    int outer=0;
                    if(i>1)
                        inner=2*scoreOfParentheses(s.substr(1,i));
                    if(i+1<n)
                        outer=scoreOfParentheses(s.substr(i+1));
                    return inner+outer;
             }
        
         }
        return 0;
    }
};