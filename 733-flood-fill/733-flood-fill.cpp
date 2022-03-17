class Solution {
    int col;
    int newC;
    void help(int x,int y,vector<vector<int>>& image){
        const int dx[] = {-1,1,0,0};
        const int dy[] = {0,0,-1,1};
        
        for(int i=0;i<4;i++){
            int r = x+dx[i];
            int c = y+dy[i];
            if(r>=0 && c>=0 && r<image.size() && c<image[0].size()&& image[r][c]==col){
                image[r][c]=newC;
                help(r,c,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        newC=newColor;
        col=image[sr][sc];
        if(col==newC)
            return image;
        image[sr][sc]=newC;
        help(sr,sc,image);
        return image;
    }
};