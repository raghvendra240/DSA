class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(n<2)
            return "";
        string res="";
        int low=0;
        int high=n-1;
        string temp,temp2;
        char newChar;
        while(low<high){
            for(int i=0;i<26;i++){
                newChar='a'+i;
                if(palindrome[low]!=newChar){
                    temp=palindrome;
                    temp[low]=newChar;
                    temp2=palindrome;
                    temp2[high]=newChar;
                    if(res=="")
                        res=min(temp,temp2);
                    else
                        res=min(res,min(temp,temp2));
                    break;
                }
            }
            ++low;--high;
        }
        return res;
    }
};