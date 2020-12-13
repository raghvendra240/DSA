
link->https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0#
https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	      
	      int k;
	      cin>>k;
	      int count=0;
	      for(int i=0;i<n;i++)
	      {
	          if(arr[i]<=k)
	           count++;
	      }
	      int bad=0;
	      for(int i=0;i<count;i++)
	      {
	          if(arr[i]>k)
	             bad++;
	      }
	      
	      int res=bad;
	      
	      for(int i=0,j=count;j<n;i++,j++)
	      {
	          if(arr[i]>k)
	            bad--;
	            
	            if(arr[j]>k)
	             bad++;
	             
	             res=min(res,bad);
	      }
	     
	      cout<<res<<endl;
	}
	return 0;
}
