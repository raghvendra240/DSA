class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto edge :  redEdges){
            adj[edge[0]].push_back({edge[1],1});
        }
        for(auto edge :  blueEdges){
            adj[edge[0]].push_back({edge[1],0});
        }
        // vector<int>vis(n,false);
        queue<vector<int>>q;
        q.push({0,-1,0});
        vector<int>res(n,-1);
        // vis[0]=true;
        while(q.empty()==false){
            auto temp=q.front();q.pop();
            int u =temp[0];
            int prevCol=temp[1];
            int dist=temp[2];
            if(res[u]==-1)
                res[u]=dist;
            for(auto &v : adj[u]){
                int newCol=v.second;
                int newNode=v.first;
                if(newNode!=-1 &&(prevCol==-1 || (newCol==1-prevCol))){
                    q.push({newNode,newCol,dist+1});
                    v.first=-1;
                }
            }
        }

        return res;
    }
};