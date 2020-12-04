There's originally an array consisting of  n integers from 1 to  n in ascending order, you need to find the number of derangement it can generate.


public class Solution {
    public int findDerangement(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        long[] dp = new long[n + 1];
        dp[1] = 0;
        dp[2] = 1;
        for(int i = 3; i <= n; i ++) {
            dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
        return (int)dp[n];
    }
}

/*

The Staggered formula is D(n) = (n-1) [D(n-2) + D(n-1)]：
For the k th element, it has k-1 positions and there are two possibilities for its position

example we have 1 2 3 4
and want to add 5

then 
1)5 is added at pos1 ans 1 is at 5
    5 X X X 1  ===>dp[n-2]

2) 1 is added at any other pos
    5 X X X X =====>dp[n-1]


so dp[i] = (i -1) * (dp[i - 1] + dp[i - 2])%1000000007 ;

*/
