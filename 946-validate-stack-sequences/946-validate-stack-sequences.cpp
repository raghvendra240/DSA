class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s;
        s.push(pushed[0]);
        int i=1;
        int j=0;
        while(i<pushed.size()){
            if(s.empty() || s.top()!=popped[j]){
                s.push(pushed[i++]);
            }else{
                s.pop();
                j++;
            }
        }
        while(!s.empty()){
            if(j>popped.size())
                return false;
            if(s.top()!=popped[j]){
                return false;
            }else{
                s.pop();
                j++;
            }
        }
        
        if(j<popped.size())
             return false;
        return true;
    }
};