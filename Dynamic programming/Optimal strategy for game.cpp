link-->https://www.interviewbit.com/problems/coins-in-a-line/

unordered_map<string,int>dp;

int help(int low,int high,vector<int>&A,bool turn)
{
    if(low>=high)
      return 0;
    string temp=to_string(low)+"|"+to_string(high)+"|"+to_string(turn);
    
    if(dp.find(temp)!=dp.end())
      return dp[temp];
    int first=help(low+1,high,A,!turn);
    if(turn)
      first+=A[low];
      
    int last= help(low,high-1,A,!turn);
    if(turn)
     last+=A[high];
     
     if(turn)
     return dp[temp]=max(first,last);
     
     return dp[temp]=min(first,last);
    
}

int Solution::maxcoin(vector<int> &A) {
    
    int n=A.size();
    dp.clear();
    return help(0,n-1,A,true);
}
