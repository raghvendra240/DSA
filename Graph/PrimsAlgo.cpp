int getMin(bool visited[],int weights[],int v)
{
    int minIndex=-1;
    
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false &&(minIndex==-1 || weights[i]<weights[minIndex]))
                   minIndex=i;
    }
    
    return minIndex;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    
    bool visited[V];
    int weights[V];
    int parent[V];
   
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        parent[i]=-1;
        weights[i]=INT_MAX;
    }
    
    weights[0]=0;
    parent[0]=-1;
    
    for(int i=0;i<V-1;i++)
    {
        int min=getMin(visited,weights,V);
        visited[min]=true;
        
        for(int j=0;j<V;j++)
        {
            if(visited[j]==false && graph[min][j]!=INT_MAX)
            {
                if(weights[j]>graph[min][j])
                { weights[j]=graph[min][j];
                 parent[j]=min;
                }
            }
        }
        
    }
    
    int res=0;
    for(int i=0;i<V;i++)
      res+=graph[i][parent[i]];
      
      return res;
    
    
}
