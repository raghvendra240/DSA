class Solution {
    unordered_map<int,vector<pair<int,int>>>adj;
    vector<bool>vis;
    int ans;
    void dfs(int u){
        vis[u]=true;
        for(auto temp : adj[u]){
            auto[v,val]=temp;
            if(vis[v])
                continue;
            ans+=val;
            dfs(v);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto connection : connections){
            adj[connection[0]].push_back({connection[1],1});
            adj[connection[1]].push_back({connection[0],0});

        }
        vis.resize(n,false);
        ans=0;
        dfs(0);
        return ans;

    }
};