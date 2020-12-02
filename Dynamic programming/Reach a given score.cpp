link->https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1#



long long int count(long long int n)
{
	long long int dp[n+1],i;
	memset(dp, 0, sizeof(dp));
	dp[0]=1;                 // If 0 sum is required number of ways is 1.
	
for(int i=3;i<=n;i++)     //Here we are only focusing on calcuating ways if we consider only 3 score
{
    dp[i]+=dp[i-3];
}

   for(int i=5;i<=n;i++)   //Here we are only focusing on calcuating ways if we consider only 5 score
{
    dp[i]+=dp[i-5];
}

for(int i=10;i<=n;i++)   //Here we are only focusing on calcuating ways if we consider only 10 score
{
    dp[i]+=dp[i-10];
}
	

	return dp[n];
}


