int find(vector<int>&arr,int x)
{
    if(arr[x]==x)
       return x;
       
     return find(arr,arr[x]);
}

static bool comp(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2)
{
    return p1.first<p2.first;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    
   vector<pair<int,pair<int,int>>>edge;
   
   for(int i=0;i<V;i++)
   {
       for(int j=0;j<V;j++)
       {
           if(graph[i][j]!=INT_MAX)
           {
               edge.push_back({graph[i][j],{i,j}});
           }
       }
   }
   
   sort(edge.begin(),edge.end(),comp);
   int res=0;
    vector<int>parent(V);
    for(int i=0;i<V;i++)
     parent[i]=i;
    
     for(int i=0,s=0;s<V-1;i++)
     {
         auto min=edge[i];
         
         int weight=min.first;
         int u=min.second.first;
         int v=min.second.second;
         
         int x=find(parent,u);
         int y=find(parent,v);
         
         if(x!=y)
         {
             res+=weight;
             parent[x]=y;
             s++;
             
         }
     }
   
   return res;
      
    
