class Solution {
    int helper(vector<vector<int>>& forest, int startX,int startY, int endX,int endY){
    if(startX == endX && startY == endY)
        return 0;
    const int dx[] = {-1,1,0,0};
    const int dy[] = {0,0,-1,1};
    int n=forest.size();
    int m=forest[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    queue<pair<int,int>>q;
    q.push({startX,startY});
    vis[startX][startY] = true;
    int step = 0;
    while(q.empty()==false){
        ++step;
       int k = q.size();
        while(k--){
             auto[x,y] = q.front();
        q.pop();
        // vis[x][y] = true;
       
        for(int i=0;i<4;i++){

            int row= x + dx[i];
            int col = y + dy[i];

            if(row>=0 && row< n && col>=0 && col<m && forest[row][col] !=0 && vis[row][col]==false){
                q.push({row,col});
                vis[row][col] =true;
                if(endX == row && endY == col)
                     return step;
            }
        }
        }
    }

    return -1;
}
public:
    int cutOffTree(vector<vector<int>>& forest) {
         int m = forest.size(), 
             n = forest[0].size(), 
             res = 0, 
             row = 0, 
             col = 0;
        vector<vector<int>> trees;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        for (int i = 0; i < trees.size(); ++i) {
            int cnt = helper(forest, row, col, trees[i][1], trees[i][2]);
            if (cnt == -1) return -1;
            res += cnt;
            row = trees[i][1];
            col = trees[i][2];
        }
        return res;
    }
};