class Solution {
    int n,m;
    
    bool exit(int x,int y,vector<int>&num)
    {
        if((x==0 || x==n-1 || y==0 || y==m-1) && (x!=num[0]  || y!=num[1]))
            return true;
        
        return false;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int ans=-1;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{entrance[0],entrance[1]}});
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        n=maze.size();
        m=maze[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        while(q.empty()==false)
        {
            auto[val,temp]=q.front();
            auto[x,y]=temp;
            q.pop();
            
            if(exit(x,y,entrance))
                return val;
            
            vis[x][y]=true;
            
            for(int k=0;k<4;k++)
            {
                int newR=x+row[k];
                int newC=y+col[k];
                
                if(newR>=0 && newR<n && newC>=0 && newC<m && maze[newR][newC]=='.'&&  vis[newR][newC]==false)
                {
                    vis[newR][newC]=true;
                    q.push({val+1,{newR,newC}});
                }
            }
            
            
        }
        
        return -1;
        
    }
};