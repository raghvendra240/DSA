class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n<2)
            return "";
        string res="";
        for(int i=0;i<n;i++){
            
            for(int j=0;j<26;j++){
                if(i == (n-1-i))
                    continue;
                if(palindrome[n-1-i]!=('a'+j))
                {
                    string temp=palindrome;
                    temp[i]='a'+j;
                    
                    if(res=="")
                        res=temp;
                    else
                        res=min(res,temp);
                    
                }
            }
        }
        
        return res;
    }
};