link->https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0#

#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int help(string &A,string &B,string &C,int indexA,int indexB,int indexC)
{
    if(indexA==-1 || indexB==-1 || indexC==-1)
      return 0;
      
     if(dp[indexA][indexB][indexC]!=-1)
       return dp[indexA][indexB][indexC];
      int ans=0;
      
      if(A[indexA]==B[indexB] && B[indexB]==C[indexC])
        ans=help(A,B,C,indexA-1,indexB-1,indexC-1)+1;
    else
  {  ans=max(help(A,B,C,indexA-1,indexB,indexC),
    max(help(A,B,C,indexA,indexB-1,indexC),help(A,B,C,indexA,indexB,indexC-1)));}
    
    return dp[indexA][indexB][indexC]=ans;
     
}

int main() {
	 int t;
	 cin>>t;
	 while(t--)
	 {
	     int n,m,k;
	     cin>>n>>m>>k;
	     string x,y,z;
	     cin>>x>>y>>z;
	     
	     memset(dp,-1,sizeof(dp));
	 
	   cout<<help(x,y,z,n-1,m-1,k-1)<<endl;
	     
	 }
	return 0;
}
