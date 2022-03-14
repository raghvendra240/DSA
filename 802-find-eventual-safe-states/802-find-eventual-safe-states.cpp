class Solution {
public:
     unordered_map<int,vector<int>>map;
 vector<int>outDeg;
 vector<bool>tempRes;
 vector<bool>vis;
 bool help(int u){
   // vis[u]=true;
   if(outDeg[u]==0)
   {
       tempRes[u]=true;
       return true;
   }
   bool res=true;
   for(auto v : map[u]){
      if(vis[v]==false){
          vis[v]=true;
         bool temp = help(v);
         if(temp==false)
             res=false;
            
      }else if(tempRes[v]==false){
          res=false;
      }
   }
   tempRes[u]=res;
   return res;
 }
 vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
 int n=graph.size();
 outDeg.resize(n,0);
 vis.resize(n,false);
 tempRes.resize(n,false);
for(int i=0;i<n;i++){
   for(int j=0;j<graph[i].size();j++){
      map[i].push_back(graph[i][j]);
      outDeg[i]++;
   }
} 
vector<int>res;
for(int i=0;i<n;i++){
   if(vis[i]==false){
       vis[i]=true;
      help(i);
   }
}
for(int i=0;i<tempRes.size();i++){
  if(tempRes[i])
     res.push_back(i);
}
return res;
}
};