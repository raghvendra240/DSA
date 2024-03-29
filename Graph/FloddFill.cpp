link->https://leetcode.com/problems/flood-fill/

class Solution {
public:
    
  void isLocationSafe(vector<vector<int>>& image,int i,int j,int color,int paint)
    {
        if(i<0 || j<0|| i>=image.size() || j>=image[0].size() || image[i][j]!=color || image[i][j]==paint)
            return;
            
        image[i][j]=paint;
        isLocationSafe(image,i+1,j,color,paint);
        isLocationSafe(image,i-1,j,color,paint);
        isLocationSafe(image,i,j+1,color,paint);
        isLocationSafe(image,i,j-1,color,paint);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() && image[sr][sc]!=newColor)
        {
            isLocationSafe(image,sr,sc,image[sr][sc],newColor);
        }
        return image;
    }
};
