class Solution {
    vector<vector<int>>res;
    vector<bool>vis;
    int n;
    void help(int u, vector<int>temp ,vector<vector<int>>&adj)
    {
        if(u==n-1)
        {
            res.push_back(temp);
            return;
        }
        
        vis[u]=true;
        for(int v: adj[u])
        {
            if(vis[v]==false)
            {
                temp.push_back(v);
                help(v,temp,adj);
                temp.pop_back();
            }
        }
        vis[u]=false;
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        
        vis.resize(15,false);
        n=graph.size();
        vector<int>temp;
        temp.push_back(0);
        help(0,temp,graph);
        return res;
        
        
    }
};