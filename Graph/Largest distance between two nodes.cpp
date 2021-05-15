link->https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/


//using Diameter concept
int res=0;
int dfs(int u,vector<int>adj[])
{

    if(adj[u].size()==0)
      return 0;
    
       
    int a1=0,a2=0;
    for(auto v:adj[u])
    {
            int x=dfs(v,adj)+1; //x is no of edges 
            
            if(x>a1) //first max
            {
                a2=a1;
                a1=x;
            }
            else if(x>a2) //sec max
              a2=x;
       
    }
 
    res=max(res,a1+a2);  //storing resfor every node
    
    return a1;  return max height of curr node
}

int Solution::solve(vector<int> &A) {
    res=0;
    int n=A.size();
    vector<int>adj[n];
   
    int root=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==-1)
         {
             root=i;
             continue;}
        
        adj[A[i]].push_back(i);   //Directed Tree so No need of Vvisited array
    }
    
    
    dfs(root,adj);
    
    return res;
    
    
}
