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
    
    
    ========================================================V2=======================================================
        Skip to content
 
Search…
All gists
Back to GitHub
@raghvendra240 
@APwhitehat
APwhitehat/tarjan.cpp
Last active 14 months ago • Report abuse
2
1
 Code
 Revisions 2
 Stars 2
 Forks 1
<script src="https://gist.github.com/APwhitehat/e2ae94b811defc7407bc320f98fd268b.js"></script>
C++ implementation of tarjan's algorithm for finding Strongly connected components
tarjan.cpp
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define MAX 100005
// C++ implementation of tarjan's algorithm for SCC
// foundat: analogous to time at which the vertex was discovered
// disc: will contain the foundat value of ith vertex(as in input graph)
// low: will contain the lowest vertex(foundat value) reachable from ith vertex(as in input graph)
// onstack: whether the vertex is on the stack st or not
// scc: will contain vectors of strongly connected vertices
// which can be iterated using
// for(auto i:scc){ // here i is a set of strongly connected component
//     for(auto j:i){ 
//         // iterate over the vertices in i
//     }
// }
int n,m,foundat=1;
vvi graph,scc;
vi disc,low; // init disc to -1
bool onstack[MAX]; //init to 0 

void tarjan(int u){
    static stack<int> st;

    disc[u]=low[u]=foundat++;
    st.push(u);
    onstack[u]=true;
    for(auto i:graph[u]){
        if(disc[i]==-1){
            tarjan(i);
            low[u]=min(low[u],low[i]);
        }
        else if(onstack[i])
            low[u]=min(low[u],disc[i]);
    }
    if(disc[u]==low[u]){
        vi scctem;
        while(1){
            int v=st.top();
            st.pop();onstack[v]=false;
            scctem.pb(v);
            if(u==v)
                break;
        }
        scc.pb(scctem);
    }
}
int main()
{
    // n= vertices of graph
    // init
    set0(onstack);
    graph.clear();graph.resize(n+1);
    disc.clear();disc.resize(n+1,-1);
    low.clear();low.resize(n+1);
    //
    // input graph here
    FOR(i,n)
        if(disc[i+1]==-1)
            tarjan(i+1);

}
@raghvendra240
 
 
Leave a comment
No file chosen
Attach files by dragging & dropping, selecting or pasting them.
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About

