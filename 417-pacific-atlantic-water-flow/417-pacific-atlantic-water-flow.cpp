class Solution {
    vector<vector<int>>vis;
    int n,m;

    void help(int x,int y,bool &pac,bool &atl,vector<vector<int>>&grid){
        // if(vis[x][y]==-1)
        // {
        //     pac=true;
        //     atl=true;
        //     return;
        // }
        const int dx[]={-1,1,0,0};
        const int dy[]={0,0,-1,1};
        vis[x][y]=1;
        
        for(int i=0;i<4;i++){
            int r=x+dx[i];
            int c=y+dy[i];
            if(r<0 || c<0){
                pac=true;
            }if(r>=n || c>=m){
                atl=true;
            }
            if(pac && atl)
            {
                vis[x][y]=0;
                return;
            }
            
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]<=grid[x][y] && vis[r][c]==0){
                help(r,c,pac,atl,grid);
                if(pac && atl)
            {
                vis[x][y]=0;
                return;
            }
            }
        }
        vis[x][y]=0;
        // vis[x][y]= pac && atl ? -1 : 0;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        n=heights.size();
        m=heights[0].size();
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
//                 if(vis[i][j]==-1){
//                     ans.push_back({i,j});
//                     continue;
//                 }
                    
               // if(vis[i][j]==0){
                bool pac=false,atl=false;
                    help(i,j,pac,atl,heights);
                    if(pac && atl){
                     ans.push_back({i,j});   
                    // }
                }
            }
        }
        return ans;
    }
};