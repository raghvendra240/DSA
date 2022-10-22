class Solution {
    int iterartion;
    int getIteration(string val, char reqType) {
        string iterationNum = "";
        string visitedNumber = "";
        for (int i = 0; i < val.size(); ++i) {
            if (val[i]==':') {
                visitedNumber = val.substr(i+1);
            }
            iterationNum += val[i];
        }
        
        if (reqType == 'I') {
            return stoi(iterationNum);
        } else {
            return stoi(visitedNumber);
        }
    }
    int dfs (int u,unordered_map<int,int>&adj, unordered_map<int,string>&vis, int vertexVisited) {

        if (vis.count(u) != 0) {
            int iterationNum = getIteration(vis[u], 'I');
            if (iterationNum == iterartion) {
                return vertexVisited - getIteration(vis[u],'V') + 1;   
            }
        }

        if (adj.count(u) != 0 && vis.count(u) == 0) {
            vis[u] = to_string(iterartion) + ":" + to_string(vertexVisited + 1);
            return dfs(adj[u],adj,vis,vertexVisited+1);
        }

        return -1;
    }
public:
    int longestCycle(vector<int>& edges) {
        unordered_map<int,int>adj;
        unordered_map<int,string>vis;
         for (int i = 0; i < edges.size(); ++i) { 
             if (edges[i]  != -1) {
                adj[i] = edges[i];   
             }
         }

        int res = -1;
        for (int i = 0; i < edges.size(); ++i) {
            if (adj.count(i) != 0 && vis.count(i) == 0) {
                iterartion++;
                res = max (res, dfs (i,adj,vis,0));
            }
        }

        return res;
    }
};