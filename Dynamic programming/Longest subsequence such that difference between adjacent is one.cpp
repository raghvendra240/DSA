link->https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1


class Solution{
    int help(int arr[],int index,int prev)
    {
        if(index<0)
          return 0;
        
        
        int len=0;
        
        if(prev==-1 || abs(arr[index]-prev)==1)
           len=1+help(arr,index-1,arr[index]);
         
         len=max(len,help(arr,index-1,prev));
         
         return len;
            
    }
public:
    int longestSubsequence(int N, int A[])
    {
        return help(A,N-1,-1);
    }
};
