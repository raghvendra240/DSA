link->https://www.interviewbit.com/problems/evaluate-expression-to-true/


unordered_map<string,int>dp;
int help(int low,int high,string &A,bool flag)
{
    
      if(low>high)
      return 0;
      
    if(low==high)
    {
        if(flag)
        return A[low]=='T';
         
         return A[low]=='F';
    }
    
    
  
      
      int res=0;
      
      string temp=to_string(low)+"|"+to_string(high)+"|"+to_string(flag);
      
      if(dp.find(temp)!=dp.end())
        return dp[temp];
      
      for(int i=low+1;i<high;i=i+2)
      {
          int leftTrue=help(low,i-1,A,true);
          int leftFalse=help(low,i-1,A,false);
          int rightTrue=help(i+1,high,A,true);
          int rightFalse=help(i+1,high,A,false);

          if(A[i]=='&')
          {
            if(flag)
            {
              res+=(leftTrue*rightTrue);
            }

            else
            {
              res+=(leftFalse*rightTrue) +(leftTrue*rightFalse)+(leftFalse*rightFalse);
            }

          }

          else if(A[i]=='|')
          {
            if(flag)
            {
              res+=(leftTrue*rightTrue)+(leftTrue*rightFalse)+(rightTrue*leftFalse);
            }

            else
              res+=(leftFalse*rightFalse);
          }

          else if(A[i]=='^')
          {
            if(flag)
               res+=(leftFalse*rightTrue)+(leftTrue*rightFalse);

             else
               res+=(leftTrue*rightTrue)+(rightFalse*leftFalse);
          }


          
      }
      
      res=res%1003;

        return dp[temp]=res;
      
}

int Solution::cnttrue(string A) {

    int n=A.size();
    dp.clear();
    return help(0,n-1,A,true);
}
