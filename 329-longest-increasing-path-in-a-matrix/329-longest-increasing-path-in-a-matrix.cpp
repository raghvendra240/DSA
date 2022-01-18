class Solution {
public:
    int dp[201][201];
     int res=0;
 int help(int x,int y,vector<vector<int>>&matrix,int prev){
    const int dx[]={-1,1,0,0};
    const int dy[]={0,0,-1,1};
     if(dp[x][y]!=-1)
         return dp[x][y];
     int ans=1;
    for(int i=0;i<4;i++){
        int newRow=x+dx[i];
        int newCol=y+dy[i];
        if(newRow<0 || newCol<0 || newRow>=matrix.size() || newCol>=matrix[0].size() || matrix[newRow][newCol]==-1)
            continue;
      if(matrix[newRow][newCol]>prev){
          int val=matrix[newRow][newCol];
          matrix[newRow][newCol]=-1;
          ans=max(ans,help(newRow,newCol,matrix,val)+1);
          matrix[newRow][newCol]=val;
      }
    }
    res=max(res,ans);
     return dp[x][y]=ans;
 }
//  int help2(int x,int y,vector<vector<int>>&matrix,vector<vector<bool>>&vis){
//     const int dx[]={-1,1,0,0};
//     const int dy[]={0,0,-1,1};
//     vis[x][y]=true;
//      int ans=1;
//     for(int i=0;i<4;i++){
//         int newRow=x+dx[i];
//         int newCol=y+dy[i];
//         if(newRow<0 || newCol<0 || newRow>=matrix.size() || newCol>=matrix[0].size() || vis[newRow][newCol]==-1)
//             continue;
//       if(matrix[newRow][newCol]<matrix[x][y]){
          
//           ans=max(ans,help2(newRow,newCol,matrix,vis)+1);
//       }
        
//     }
//     vis[x][y]=false;
//     res=max(res,ans);
//     return ans;
//     }
//  }
    // res=max(res,ans);
 int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>>vis;
        memset(dp,-1,sizeof(dp));
        // help(0,0,matrix,vis);
     // vis.clear();
     // vis.resize(n,vector<bool>(m,false));
     // vector<vector<bool>>vis2(n,vector<bool>(m,false));
    // help2(0,0,matrix,vis2);
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             // vis.clear();
             // vis.resize(n,vector<bool>(m,false));
             // vis[i][j]=true;
             int val=matrix[i][j];
             matrix[i][j]=-1;
             help(i,j,matrix,val);
             matrix[i][j]=val;
         }
     }
        return res;
    }
};