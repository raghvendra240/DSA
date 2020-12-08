
link-->https://practice.geeksforgeeks.org/problems/negative-weight-cycle/0#

#include <bits/stdc++.h>
using namespace std;

class edge
{
    public:
    int u,v,wt;
    
    edge(int u,int v,int wt)
    {
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
    
};
int main() {
		int t;
	cin>>t;
	while(t--)
	{
	    int v,e;
	    cin>>v>>e;
	    vector<edge>E;
	   
	    for(int i=0;i<e;i++)
	    {
	        int u,v,wt;
	        cin>>u>>v>>wt;
	   
	       E.push_back({u,v,wt});
	       
	    }
	    
	    vector<int>dist(v,INT_MAX);
	    dist[0]=0;
	    
	    for(int i=1;i<=v-1;i++)
	    {
	      for(int j=0;j<E.size();j++)
	      {
	          int u=E[j].u;
	          int v=E[j].v;
	          int wt=E[j].wt;
	          
	          if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt)
	          {
	              dist[v]=dist[u]+wt;
	          }
	      }
	        
	    }
	    

	        
	        int j=0;
	     for(j=0;j<E.size();j++)
	      {
	          int u=E[j].u;
	          int v=E[j].v;
	          int wt=E[j].wt;
	          
	          if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt)
	          {
	              cout<<1<<endl;
	              break;
	          }
	      }
	      
	      if(j==E.size())
	      cout<<0<<endl;
	}
	
	return 0;
}
