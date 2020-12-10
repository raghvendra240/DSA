https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/submissions/

====================My soln

#include<bits/stdc++.h>
using namespace std;

int n;
int timer;
vector<vector<int>>adj;
vector<int>startTime;
vector<int>endTime;
vector<bool>vis;

void fillTime(int u)
{
      vis[u]=true;
      startTime[u]=timer++;

      for(int v:adj[u])
      {
        if(vis[v]==false)
          fillTime(v);
      }

      endTime[u]=timer++;

}

bool isSubTree(int x,int y)  //Check Whether x is subtree of Y or not
{
     if(startTime[y]<startTime[x] && endTime[y]>endTime[x])
        return true;

        return false;
}


int main()
{
   
   cin>>n;
   adj.resize(n+1);
   startTime.resize(n+1,0);
   endTime.resize(n+1,0);
   vis.resize(n+1,false);
   
   for(int i=1;i<=n-1;i++)
     {
         int u,v;
         cin>>u>>v;

         adj[u].push_back(v);

     } 

     fillTime(1);  

     int q;
     cin>>q;
   
     while(q--)
     {
       int way,x,y;
       cin>>way>>x>>y;

       if(isSubTree(x,y)==false && isSubTree(y,x)==false)
                       {
                         cout<<"NO"<<endl;
                         continue;
                       }

        if(way==0)
        {
          if(isSubTree(y,x))
            cout<<"YES\n";
          else
          {
             cout<<"NO\n";
          }
          
        }
        else
        {
             if(isSubTree(x,y))
                cout<<"YES\n";

                else
                {
                  cout<<"NO\n";
                }
                
        }
        
     }

     return 0;
}


================================================Editorial
#include<bits/stdc++.h>
using namespace std;
int vertex;
vector<vector<int> > tree; //used for representing the tree
vector<bool> visited;
vector<int> starttime; // starttime[i] notes the time at which DFS enters node i
vector<int> endtime; // endtime[i] notes the time at which DFS exits node i
int timer = 0; // a global variable that stores the timer at that instant
void  makeTree()  // takes the input and creates a directed graph representing the tree
{
    scanf("%d",&vertex);
    tree.resize(vertex+1);
    for(int i = 1; i < vertex ; i++)
    {   int x,y;
        scanf("%d%d",&x,&y);
        tree[x].push_back(y);
    }
}
void measureTime(int v) // Performs Depth First Search
{
    visited[v] = 1;
    starttime[v] = timer++;
    for(int i = 0 ; i < tree[v].size() ; i++) // calling measureTime() for adjacent nodes of node v and performing DFS
    {
        if( visited [ tree[ v ][ i ] ] == 0  )
            measureTime(tree[v][i]);
    }
    endtime[v] = timer++;
}
int check(int x, int y)
{
    if( starttime[x] > starttime[y] && endtime[x] < endtime[y] ) // checks weather node x lies in the subtree of node y or not
        return 1;
    return 0;
}
int main()
{
    makeTree();
    visited.resize(vertex+1,0);
    starttime.resize(vertex+1,0);
    endtime.resize(vertex+1,0);
    measureTime(1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int type,x,y;
        scanf("%d%d%d",&type,&x,&y);
        if( !check(x,y) && !check(y,x) )
        {
            printf("NO\n");
            continue;
        }
        if(type == 0)
        {
            if(check(y,x) == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(check(x,y) == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
