// adj : adjacency list of the given graph
// N : number of vertices
void dfs(int u,vector<int>&disc,vector<int>&low,stack<int>&s,vector<bool>&rec,vector<int> adj[])
{
    static int time=0;
    low[u]=disc[u]=++time;
    s.push(u);
    rec[u]=true;
    
    for(auto v:adj[u])
    {
        if(disc[v]==-1)
        {
            dfs(v,disc,low,s,rec,adj);
            
            low[u]=min(low[u],low[v]);
            
        }
        else if(rec[v]==true)
         low[u]=min(low[u],disc[v]);
    }
    
    if(low[u]==disc[u])
    {
        while(s.top()!=u)
        {
            cout<<s.top()<<" ";
            rec[s.top()]=false;
            s.pop();
        }
         cout<<s.top();
            rec[s.top()]=false;
            s.pop();
            cout<<",";
        
    }
    
}
void find(vector<int> adj[], int N) {

    vector<int>disc(N,-1);
    vector<int>low(N);
    vector<bool>smem(N,false);
    stack<int>s;
    
    for(int i=0;i<N;i++)
    {
        if(disc[i]==-1)
          dfs(i,disc,low,s,smem,adj);
    }
