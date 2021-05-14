# Graph Representation

- ### Unweighted 
```sh
vector<int>adj[N]
unordered_map<int,vector<int>>adj
```

- ### Weighted 
```sh
vector<pair<int,int>>adj[N]
unordered_map<int,vector<pair<int,int>>>adj
```

# Cycle Detection
### In UnDirected
- #### using DFS
 ```sh
 for any edge U->V
       if(vis[v]==true && v!=parent)
          cycle is there
```
- #### Using Union_find Algo


### In Directed
- There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is joining a node to itself (self-loop) or one of its ancestor in the tree produced by DFS. 
- #### using DFS
 ```sh
Maintain a array for nodes in recursion and at any point if vis[v]==true and inRecursion[v]==true then there is cycle(Back edge)
```

- #### Using BFS(Kahn's Algo)
- #### Using Three Colours 
 ```sh
   make array of three colores
   White-> Not visited
   Grey->In recurion(Like we used recursion array in DFS)
   Black->Processed all its decendent
   
   enum Color {WHITE, GRAY, BLACK};
     int *color = new int[V];
    for (int i = 0; i < V; i++)
        color[i] = WHITE;
        
Code->https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/
   
 ```
 
 # Topological Sorting
 Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
 
 - #### Kahn's Algo
 ```
 1 Store indegree of evey vertex
 2 create queue q
 3 Add all 0 indegree vertices in q
 
 while(q is not empty)
 {
     u=q.pop();
     print u
     
     for(every edge u->v)
     {
         if(indeg(v)==0)
           q.push(v);
     }
 }
 ```
 - #### Using DFS
 
```
void help(vector<int> adj[],int v,bool vis[],stack<int>&s,int temp)
{
    vis[temp]=true;
    
    for(auto x:adj[temp])
    {
        if(vis[x]==false)
           help(adj,v,vis,s,x);
    }
    
    s.push(temp);
}

vector<int> topoSort(int V, vector<int> adj[]) {
   
   stack<int>s;
   bool vis[V+1];
   memset(vis,false,sizeof(vis));
   vector<int>res;
   
   for(int i=0;i<V;i++)
   {
       if(vis[i]==false)
       {
           help(adj,V,vis,s,i);
       }
   }
   
   
  while(s.empty()==false)
  {
      res.push_back(s.top());
      s.pop();
  }
   
   return res;
}
```

# Minimum spanning Tree

- ##### A spanning tree is a subset of Graph G, which has all the vertices covered with minimum possible number of edges. Hence, a spanning tree does not have cycles and it cannot be disconnected..  (V vertices then V-1 edges)
- ##### when sum of all edges is minimum then it is called MST
- ##### Algo to find MST
    - ##### Prim's Algo 
         - Greedy
         - Graph should be weighted , undirected and connected
         - Always pick min. weight vertex (No cycle)
         - O(V^2)
         - https://github.com/raghvendra240/InterviewPrep/blob/main/Graph/PrimsAlgo.cpp
 
    - ##### Krushkal's Algo
       - Greedy
       - Pick min weight Edge(chance of cycle so use Disjoint set to detect cycle)
       - O(ELogE + ELogV)
       - https://github.com/raghvendra240/InterviewPrep/blob/main/Graph/Kruskal%20Algo.cpp
       

# Shortest Path Algo

- ### Unweighted Graph
    - ##### Use BFS
    
- ### weighted Graph
    - ##### For general Graph use Bellman-ford (VE)
         - https://github.com/raghvendra240/InterviewPrep/blob/main/Graph/BellmanFordAlgo.cpp
    - ##### No negative weight use Dijkstra's Algo(E+Vlogv)
         - https://github.com/raghvendra240/InterviewPrep/blob/main/Graph/Dijkstra's%20Algo.cpp
    - ##### Directed Acycic Graph (DAG) use Topological sort(V+E)
    - ##### All Pair shortest path Use Floyd Warshall ALgo
         - https://github.com/raghvendra240/InterviewPrep/blob/main/Graph/Floyd%20Warshall.cpp
    
- ### If we have only two type of weight then use dequeue instead of queue in BFS(0/1 BFS)


### Dijkstra Algo
- ##### Diff between BFS and Dijkstra -> BFS uses queue in extraction opertaion(O1) and dijkstra uses priorityQueue(OlogV)
- ##### Different implementation for extraction
     - Adjacency Matrix OV
     - using Set Ologv
     - Priority queue of STL but it does not support Decrease Key. so we make pq of pair<weight,vertex> and dec. key operation we again insert same vertex with dec. weight

- ##### If there is a negative weight in the graph, then the algorithm will not work properly. Once a node has been marked as "visited", the current path to that node is marked as the shortest path to reach that node. And negative weights can alter this if the total weight can be decremented after this step has occurred.
  


### BellmanFord Algo
  ##### Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edge



# Connected Componenets
#### For undirected graph we can use DFS or BFS
#### For Directed graph we canot use DFS/BFS
  - Kosaraju (https://github.com/raghvendra240/InterviewPrep/blob/main/Graph/Kosaraju%20Algo.cpp)
  - Tarjans  (https://github.com/raghvendra240/InterviewPrep/blob/main/Graph/Tarjan's%20Algo.cpp)
 
                
    



