class Solution {
public:
    string simplifyPath(string path) {
        queue<string>s;
        int i=path.size()-1;
        while(i>=0){
            int j=i;
            string temp="";
            while(j>=0 && path[j]!='/'){
                temp+=path[j];
                --j;
            }
            if(temp.length()){
                reverse(temp.begin(),temp.end());
                s.push(temp);
            }
            i=j-1;
        }
        
        string res="";
        int toSkip=0;
        while(s.empty()==false){
            string temp=s.front();s.pop();
            if(temp==".")
                continue;
            if(temp==".."){
                ++toSkip;
                continue;
            }
            if(toSkip){
                --toSkip;
                continue;
            }
            res='/'+temp+res;
        }
        return res.length()==0 ? "/"  : res;
    }
};