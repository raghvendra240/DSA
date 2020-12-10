link->https://leetcode.com/problems/cheapest-flights-within-k-stops/

---------------DFS+DP-----------------------------
class Solution {
    int dp[101][101];
    
   int help( vector<pair<int,int>>adj[],int src,int dest,int k)
    {
      if(src==dest)
            return 0;
        if(k<=-1)
          return INT_MAX;
        if(dp[src][k]!=-1)
            return dp[src][k];
        int res=INT_MAX;
        
        for(auto x:adj[src])
        {
            int v=x.first;
            int wt=x.second;
            
            int ans=help(adj,v,dest,k-1);
            if(ans!=INT_MAX)
                 res=min(res,ans+wt);
                
        }
        
        return dp[src][k]=res;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
      vector<pair<int,int>>adj[n];
        
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            
            adj[u].push_back({v,wt});
            
        }
        memset(dp,-1,sizeof(dp));
        
     
        vector<bool>vis(n,false);
        int curr=0;
        
       int x=help(adj,src,dst,K);
           
           return x==INT_MAX?-1:x;

      
    }
};

=============================BFS based=============================================


class Solution {

    struct Tri{
        
        int node;
        int k,
        price;
    };
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
      vector<pair<int,int>>adj[n];
        
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];
            
            adj[u].push_back({v,wt});
           
        }
    
         queue<Tri>q;
        q.push({src,K,0});
        
        int res=INT_MAX;
        while(q.empty()==false)
        {
            auto[u,k,price]=q.front();
            q.pop();
           
            if(u==dst)
               { res=min(res,price);
                 
                  continue;
               }
            
           //vis[u]=true;
            if(u!=src)
               k--;
           
  if( (k)>=0)
           { for(auto temp:adj[u])
            {
                int v=temp.first;
                int p=temp.second;
             
                  if(p+price<res)
                     q.push({v,k,price+p});
            }}
            
        }
        
        
    return res==INT_MAX?-1:res;
      
    }
};
