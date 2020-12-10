link->https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0#

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int v;
	    cin>>v;
	    
	    int G[v][v];
	    
	    for(int i=0;i<v;i++)
	    {
	        for(int j=0;j<v;j++)
	        cin>>G[i][j];
	    }
	    
	    for(int k=0;k<v;k++)
	    {
	        for(int i=0;i<v;i++)
	        {
	            for(int j=0;j<v;j++)
	            {
	                if(G[i][j]>G[i][k]+G[k][j])
	                  G[i][j]=G[i][k]+G[k][j];
	            }
	        }
	    }
	    
	     for(int i=0;i<v;i++)
	        {
	            for(int j=0;j<v;j++)
	            {
	               if(G[i][j]==10000000)
	                 cout<<"INF ";
	                 else
	                  cout<<G[i][j]<<" ";
	            }
	            cout<<endl;
	        }
	    
	}
return 0;
	
}
