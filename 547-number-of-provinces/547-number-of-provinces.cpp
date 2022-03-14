class Solution {
public:
     vector<bool>vis;
 unordered_map<int,vector<int>>map;
 void help(int u){
   vis[u]=true;
   for(auto v: map[u]){
      if(!vis[v])
         help(v);
   }
   
 }
 int findCircleNum(vector<vector<int>>& isConnected) {
        int res=0;
        int n = isConnected.size();
        vis.resize(n,false);
        for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
               if(isConnected[i][j]){
                  map[i].push_back(j);
                  map[j].push_back(i);
               }
            }
         }
        for(int i=0;i<n;i++){
         if(vis[i]==false){
         help(i);
         ++res;
        }
        
    }
     return res;
 }
};