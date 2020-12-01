link->https://www.interviewbit.com/problems/increasing-path-in-matrix/

int dp[1001][1001];
bool check(vector<vector<int>>&A,int r,int c)
{
      if(r>=A.size() || c>=A[0].size())
      return false;
      
      return true;
}

int help(vector<vector<int>>&A,int r,int c,bool &res)
{
 
    if(r==A.size()-1 && c==A[0].size()-1)
       res=true;
       
          if(dp[r][c]!=-1) 
      return dp[r][c];
      
     int down=0;
     int right=0;
     if(check(A,r+1,c) && A[r+1][c]>A[r][c])
        down=help(A,r+1,c,res);
        
    if(check(A,r,c+1) &&A[r][c+1]>A[r][c])
      right=help(A,r,c+1,res);
      
      return dp[r][c]=max(down,right)+1;
      
}

int Solution::solve(vector<vector<int> > &A) {
    
  memset(dp,-1,sizeof(dp));
    bool res=false;
   int x=help(A,0,0,res);

   
  if(res)
    return x;
  
  return -1;
    
}
