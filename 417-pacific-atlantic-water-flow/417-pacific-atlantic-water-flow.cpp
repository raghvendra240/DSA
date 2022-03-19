class Solution {
    vector<vector<bool>>pac;
    vector<vector<bool>>atl;
    vector<vector<int>>ans;
    int n,m;
public:
    void help(int x,int y,vector<vector<bool>>&vis,vector<vector<int>>&grid){
        if(vis[x][y])
            return;
        vis[x][y]=true;
        const int dx[]={-1,1,0,0};
        const int dy[]={0,0,-1,1};
        if(pac[x][y] && atl[x][y]){
            ans.push_back({x,y});
        }
        for(int i=0;i<4;i++){
            int r=x+dx[i];
            int c=y+dy[i];
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]>=grid[x][y])
                help(r,c,vis,grid);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
        we will try to reach some points from cornors
        if the point is visited from right to bottom then will mark it as atl.
        and from top or left = pac;
        and if any value true for both then we can rach both sides from there
        so push the result
        */
        n=heights.size();
        m=heights[0].size();
        pac=atl=vector<vector<bool>>(n,vector<bool>(m,false));
        /*left and right*/
        for(int i=0;i<n;i++){
            help(i,0,pac,heights);
            help(i,m-1,atl,heights);
        }
        /*top and bottom*/
        for(int i=0;i<m;i++){
            help(0,i,pac,heights);
            help(n-1,i,atl,heights);
        }
        return ans;
    }
};