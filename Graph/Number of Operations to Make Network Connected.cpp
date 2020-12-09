link->https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/

Network can be connected if there are at least N-1 edges. Otherwise connection is not possible.
Now the minimum number of connection extraction will be the Number of Connected Component -1.



class Solution {
    
    void dfs(int u,vector<int>adj[],vector<bool>&vis)
    {
        vis[u]=true;
       // wire++;
        for(int v:adj[u])
        {
            
            if(vis[v]==false)
              {
               dfs(v,adj,vis);}
        }
        
        return;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int totalEdges=connections.size();
        if(totalEdges<n-1)
             return -1;
        
       // vector<pair<int,int>>scc;
        vector<int>adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
           
            if(vis[i]==false)
            { 
                 
                dfs(i,adj,vis);
               count++;
                
            
            }
        }
        
        
       return count-1;
        
    }
};
