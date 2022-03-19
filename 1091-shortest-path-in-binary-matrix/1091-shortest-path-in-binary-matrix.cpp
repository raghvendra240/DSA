class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0] || grid[n-1][n-1])
            return -1;
      const int dx[]={-1,1,0,0,1,-1,1,-1};
      const int dy[]={0,0,-1,1,1,-1,-1,1};
      queue<pair<int,int>>q;
      q.push({0,0});
     grid[0][0]=1;
      while(q.empty()==false){
        auto[x,y]=q.front();
          q.pop();
        if(x==n-1 && y==n-1)
            return grid[x][y];
        for(int i=0;i<8;i++){
            int r=x+dx[i];
            int c=y+dy[i];
            if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==0){
                q.push({r,c});
                grid[r][c]=grid[x][y]+1;
            }
        }

      }
      return -1;
    }
};