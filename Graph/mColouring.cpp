link->https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
      https://www.prepbytes.com/blog/backtracking-interview-questions/m-coloring-problem/

#include<iostream>
        #define V 100
        using namespace std;
        int isSafe(int v, int graph[V][V],int color[], int c) 
        { 
            for (int i = 0; i < V; i++) 
                if ( 
                    graph[v][i] && c == color[i]) 
                    return 0; 
            return 1; 
        } 
        int colour(int graph[V][V], int m,int color[], int v) 
        { 
            if (v == V) 
                return 1; 
            for (int c = 1; c <= m; c++) 
            { 
                if (isSafe( 
                        v, graph, color, c)) { 
                    color[v] = c; 
                    if ( colour(graph, m, color, v + 1)== 1) 
                        return 1; 
                    color[v] = 0; 
                } 
            } 
            return 0; 
        } 
        int graphColoring(int graph[V][V], int m) 
        { 
            int color[V]; 
            for (int i = 0; i < V; i++) 
                color[i] = 0; 
            if ( 
                colour(graph, m, color, 0)== 0) { 
                return 0; 
            } 
            return 1; 
        } 
        int main() 
        { 
            int t;
            cin>>t;
            while(t--)
            {
            int n,e;
            cin>>n>>e;
            int graph[V][V];
            for(int i=0;i<V;i++)
            {
            for(int j=0;j<V;j++)
            graph[i][j]=0;
            }
            while(e--)
            {
            int u,v;
            cin>>u>>v;
            graph[u][v]=1;
            graph[v][u]=1;
            }
            int m; // Number of colors 
            cin>>m;
            cout<<graphColoring(graph, m)<<endl; 
            }
        return 0; 
    } 
