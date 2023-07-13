//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	stack<int>s;
	vector<bool>vis;
	void dfs(int u , vector<int> adj[]) {
	    for(int v : adj[u]) {
	        if(!vis[v]) {
	            vis[v] = true;
	            dfs(v, adj);
	        }
	    }
	    s.push(u);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vis = vector<bool>(V, false);
	   for(int v = 0; v < V ; ++v) {
	        if(!vis[v]) {
	            vis[v] = true;
	            dfs(v, adj);
	        }
	   }
	   vector<int>res;
	   while(!s.empty()) {
	       res.push_back(s.top());
	       s.pop();
	   }
	   return res;
	    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends