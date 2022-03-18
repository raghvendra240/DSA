class Solution {

    bool help(int x,int y,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
         const int dx[]={-1,1,0,0};
         const int dy[]={0,0,-1,1};
bool res= true;
        for(int i=0;i<4;i++){
            int r=x+dx[i];
            int c=y+dy[i];

            if(r>=0 && c>=0 && r<grid1.size() && c<grid1[0].size() && grid2[r][c]==1 ){
                if(grid1[r][c]!=1)
                    res=false;
                
                    grid2[r][c]=-1;
                    if(help(r,c,grid1,grid2)==false)
                        res=false;
        }
        }
        return res;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
           int res = 0;
        
        int n = grid1.size();
        int m = grid1[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    grid2[i][j]=-1;
                    res+=help(i,j,grid1,grid2);
                }
            }
        }
        return res;
    }
};