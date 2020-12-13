https://leetcode.com/problems/plus-one/
  https://www.interviewbit.com/problems/add-one-to-number/


class Solution {
    void help(string &s,int index,int x)
{
    if(x==0)
       return;
    if(index<0 && x!=0)
    {
        s.insert(0,to_string(x));
        return;
    
    }
    else if(index<0)
    {
        return;
    }
    
    
    
    if(x+(s[index]-'0')>9)
        {
            int num=s[index]-'0';
            // cout<<num<<endl;
            num+=x;
            int k=num%10;
        
            string temp=to_string(k);
            // cout<<ch<<endl;
            s[index]=temp[0];
            num=num/10;
            help(s,index-1,num);
        }
        else
        {int num=s[index]-'0';
        // cout<<num<<endl;
            num+=x;
         // cout<<num<<endl;
            // char ch=num;
            // cout<<ch<<endl;
         string temp=to_string(num);
             s[index]=temp[0];
            
        }
        
}
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int>&A=digits;
        
        string ans="";
    
    int i=0;
    while(i<A.size() && A[i]==0)
        
        i++;
      
      if(i==A.size())
        return {1};
    
    for(;i<A.size();i++)
    {
        ans+=(to_string(A[i]));
    }
    
  
    help(ans,ans.size()-1,1);
    
    
    vector<int>res;
    
    for(char x:ans)
    {
        int num=x-'0';
        res.push_back(num);
    }
    
    return res;
        
    }
};
