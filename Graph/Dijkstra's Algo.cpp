
================================This method uses Adjacency matrix and TC O(V2)========================================
/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
int get(vector<bool>&vis,int v,vector<int>&dis)
{
    int index=-1;
    
    for(int i=0;i<v;i++)
    {
        if(  vis[i]==false &&(index==-1 ||  dis[i]<=dis[index]))
             index=i;
    }
    
    return index;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int>dist(V,INT_MAX);
    vector<bool>vis(V,false);
    dist[src]=0;
    
     for(int k=0;k<V;k++)
    {
        int min=get(vis,V,dist);
        vis[min]=true;
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==false && g[min][i] && dist[min]!=INT_MAX && dist[i]>dist[min]+g[min][i])
            {
                dist[i]=dist[min]+g[min][i];
                
            }
             
        }
    }
    
    return dist;
}
