bool dfs(int u,vector<int>adj[],vector<bool>&vis,vector<bool>&rec)
{
    vis[u]=true;
    rec[u]=true;
    for(int v:adj[u])
    {
        if(vis[v]==false)
        {
            if(dfs(v,adj,vis,rec))
               return true;
               
        }
        else if(rec[v]==true)
           return true;
          
    }
    
    rec[u]=false;
    
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<int>adj[A];
    
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
    }
    vector<bool>vis(A,false);
    vector<bool>rec(A,false);
    
    for(int i=0;i<A;i++)
    {
        if(vis[i]==false)
        {
            if(dfs(i,adj,vis,rec)==true)
              return 1;
        }
    }
    
    return 0;
}
