link-->https://www.interviewbit.com/problems/delete-edge/


An efficient method can solve this problem in linear time by calculating the sum of both subtrees using total sum of the tree. We can get the sum of other tree by subtracting sum of one subtree from the total sum of tree, in this way subtree sum product can be calculated at each node in O(1) time.
First we calculate the weight of complete tree and then while doing the DFS at each node, we calculate its subtree sum, by using these two values we can calculate subtree sum product and maintain the maximum among all.



long res=0;
void dfs(int u,int par,vector<int>adj[],vector<int>&A,long sum)
{
    int x=A[u];
    for(int v:adj[u])
    {
      if(v!=par)
      {
          dfs(v,u,adj,A,sum);
          x+=A[v];
      }
    }
    
    A[u]=x;
    
    if(u==0)
      return;
    
    res=max(res,(x*(sum-x))%1000000007)%1000000007;
    
   
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    
    int n=A.size();
    
    vector<int>adj[n];
    
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
        adj[B[i][1]-1].push_back(B[i][0]-1);
    }
   res=0;
   long sum=0;
   
   for(int x:A)
       sum+=x;
   dfs(0,-1,adj,A,sum);
   
   return res;
    
    
    
}
