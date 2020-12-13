
https://www.interviewbit.com/problems/largest-number/

static bool comp(string &s1,string &s2)
{
    return (s1+s2)>(s2+s1);
}

string Solution::largestNumber(const vector<int> &A) {
    
    vector<string>nums(A.size());
    
    for(int i=0;i<A.size();i++)
       nums[i]=to_string(A[i]);
       
      sort(nums.begin(),nums.end(),comp);
      string res="";
      for(auto x:nums) 
        res+=x;
        
        if(res[0]=='0')
          return "0";
        
        return res;
}
