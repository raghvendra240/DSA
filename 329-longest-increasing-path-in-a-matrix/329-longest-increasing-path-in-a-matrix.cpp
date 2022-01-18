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
        //-1 represent visited
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

 int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        memset(dp,-1,sizeof(dp));
      
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             int val=matrix[i][j];
             matrix[i][j]=-1;
             help(i,j,matrix,val);
             matrix[i][j]=val;
         }
     }
        return res;
    }
};