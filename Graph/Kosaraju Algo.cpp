
/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfs(int src,vector<int>adj[],vector<bool>&vis,stack<int>&s)
{
    vis[src]=true;
    
    for(int x:adj[src])
    {
        if(vis[x]==false)
          dfs(x,adj,vis,s);
    }
    
    s.push(src);
}

void fillrev(vector<int>rev[],vector<int>adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int x:adj[i])
        {
            rev[x].push_back(i);
        }
    }
}

void dfs2(int src,vector<int>adj[],vector<bool>&vis)
{
    vis[src]=true;
    
    for(int x:adj[src])
    {
        if(vis[x]==false)
          dfs2(x,adj,vis);
    }
    
   
}

int kosaraju(int V, vector<int> adj[])
{
    
    vector<bool>vis(V,false);
    int res=0;
    stack<int>s;
    
    for(int i=0;i<V;i++)
    {
        if(vis[i]==false)
            dfs(i,adj,vis,s);
    }
    
    // while(s.empty()==false)
    //  s.pop();
     for(int i=0;i<V;i++)
      vis[i]=false;
    
    vector<int>rev[V];
    
    fillrev(rev,adj,V);
    
    while(s.empty()==false)
    {
        int i=s.top();
        s.pop();
        if(vis[i]==false)
        {
            dfs2(i,rev,vis);
            res++;
        }
    }
    
 return res;

}
