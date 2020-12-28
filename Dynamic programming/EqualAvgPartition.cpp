https://www.interviewbit.com/problems/equal-average-partition/
Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.

Return both parts (If exist). If there is no solution. return an empty list.



bool check(int index,int sum,int count,vector<int>&A,vector<pair<int,int>>&res,unordered_map<string,bool>&dp)
{
    if(count==0)
      return dp[to_string(index)+"|"+to_string(sum)+"|"+to_string(count)]=(sum==0);
      
      if(index>=A.size())
        return false;
        
        if(dp.find(to_string(index)+"|"+to_string(sum)+"|"+to_string(count))!=dp.end())
          {
              return dp[to_string(index)+"|"+to_string(sum)+"|"+to_string(count)];}
   
    
    if(A[index]<=sum)
    {
        res.push_back({A[index],index});
        
        if(check(index+1,sum-A[index],count-1,A,res,dp))
              return dp[to_string(index)+"|"+to_string(sum)+"|"+to_string(count)]=true;
        res.pop_back();
    }
    
        if(check(index+1,sum,count,A,res,dp))
              return dp[to_string(index)+"|"+to_string(sum)+"|"+to_string(count)]=true;
              
              return dp[to_string(index)+"|"+to_string(sum)+"|"+to_string(count)]=false;
    
}
vector<vector<int> > Solution::avgset(vector<int> &A) {
    
    int n=A.size();
    sort(A.begin(),A.end());
    unordered_map<string,bool>dp;
    vector<vector<int>>ans;
    int sum=0;
    
    for(auto x:A)
     sum+=x;
     
     for(int i=1;i<=n-1;i++)
     {
         if((sum*i)%n==0)
      {
          int temp=sum*i;
          temp=temp/n;
          
          vector<pair<int,int>>res;
         
          if(check(0,temp,i,A,res,dp))
          {
              //ans.push_back(res);
              vector<int>first;
              vector<int>sec;
              
              for(auto x:res)
              {
                  first.push_back(x.first);
                  A[x.second]=-1;
              }
               
              for(int j=0;j<n;j++)
              {
                  if(A[j]>=0)
                    sec.push_back(A[j]);
              }
              
              
              return {first,sec};
          }
      }
     }
     
     return {};
}
