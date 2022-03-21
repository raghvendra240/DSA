class Solution {
    unordered_map<int,vector<int>>map;
    unordered_set<int>vis;
    void dfs(int u){
        vis.insert(u);
        for(auto v : map[u]){
            if(vis.count(v)==0)
                dfs(v);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        for(int i=0;i<n;i++){
            for(auto room : rooms[i]){
                map[i].push_back(room);
            }
        }
        vis.insert(0);
        dfs(0);
        return vis.size()==n;
    }
};