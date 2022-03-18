class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res=-1;
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=-1;
                    q.push({i,j,i,j});
                }
            }
        }
        const int dx[]={-1,1,0,0};
        const int dy[]={0,0,-1,1};
        while(q.empty()==false){
            auto temp=q.front();
            int x=temp[0];
            int y=temp[1];
            int orgX=temp[2];
            int orgY=temp[3];
            q.pop();
            for(int i=0;i<4;i++){
                int r=x+dx[i];
                int c=y+dy[i];
                
                if(r>=0 && c>=0 &&r<n && c<m && grid[r][c]==0){
                    res=max(res,abs(r-orgX)+abs(c-orgY));
                    grid[r][c]=-1;
                    q.push({r,c,orgX,orgY});
                }
            }
            
        }
        return res;
    }
};