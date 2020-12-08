


int dfs(int u,vector<int>adj[],vector<bool>&vis, vector<int>&col)
{
    vis[u]=true;
    
    for(int v:adj[u])
    {
        if(vis[v]==false)
        {
            col[v]=1-col[u];
            if(dfs(v,adj,vis,col)==0)
              return 0;
        }
        else if(col[v]!=(1-col[u]))
             return 0;
    }
    
    return 1;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    int n=A;
    vector<int>adj[n];
    
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }
    
    vector<int>col(n,-1);
    vector<bool>vis(n,false);
  
    for(int i=0;i<A;i++)
    {
        if(vis[i]==false)
       { col[i]=0;
        if(dfs(i,adj,vis,col)==0)
          return 0;}
    }
    return 1;
}
