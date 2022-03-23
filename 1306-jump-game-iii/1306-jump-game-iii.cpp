class Solution {
    unordered_map<int,vector<int>>adj;
    vector<int>nums;
    vector<bool>vis;
    int n;
    bool dfs(int u){
        vis[u]=true;
        if(nums[u]==0)
            return true;
        for(auto v : adj[u]){
            if(!vis[v] && dfs(v))
                return true;
        }
        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        nums=arr;
        vis.resize(n,false);
        for(int i=0;i<arr.size();++i){
            if(i+arr[i]<n)
                adj[i].push_back(i+arr[i]);
            if(i-arr[i]>=0)
                adj[i].push_back(i-arr[i]);

        }
        return dfs(start);


    }
};