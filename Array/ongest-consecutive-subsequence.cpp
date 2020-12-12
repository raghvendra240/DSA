
link->https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

int findLongestConseqSubseq(int arr[], int N)
{
      
      unordered_set<int>set;
      int res=0;
      for(int i=0;i<N;i++)
      {set.insert(arr[i]);
      }
      
      for(int i=0;i<N;i++)
      {
          if(set.count(arr[i]-1)==0)
          {
              int curr=1;
              while(set.count(arr[i]+curr)!=0)
                curr++;
                
                res=max(res,curr);
              
          }
      }
      
      return res;
      
      
}
