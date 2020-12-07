============Method 1 using DFS================

int dfs(vector<int>adj[],int u,int par,vector<bool>&vis)
{
    vis[u]=true;
    
    for(auto v:adj[u])
    {
        if(vis[v]==false)
        {
            if(dfs(adj,v,u,vis))
              return 1;
        }
        else if(v!=par)
          return 1;
    }
    
    return 0;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    
     vector<int>adj[A];
   // vector<int>indeg(A,0);
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
        
        
    }
    vector<bool>vis(A,false);
    
   for(int i=0;i<A;i++)
   {
       if(vis[i]==false)
       {
           if(dfs(adj,i,-1,vis))
             return 1;
       }
   }
   
   return 0;
    
}
====================================Method 2 using Disjoint set=======================


int find(int x,vector<int>&par)
{
    if(par[x]==-1)
      return x;
      
      return par[x]=find(par[x],par);
}

int Solution::solve(int A, vector<vector<int> > &B) {
    
     vector<int>par(A,-1);
   // vector<int>indeg(A,0);
    for(int i=0;i<B.size();i++)
    {
       int u=B[i][0]-1;
       int v=B[i][1]-1;
       
       int a=find(u,par);
       int b=find(v,par);
       
       if(a!=b)
       {
           par[a]=b;
       }
       else
        return 1;
        
    }
   
   
   return 0;
    
}
