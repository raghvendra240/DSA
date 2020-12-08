=================Leetcode repetition of same char is not allowed======================================
                        so dont got to already visited
                        
                        
  class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Go through each character on the board
        for (int i = 0; i < board.size(); ++ i) {
            for (int j = 0; j < board[0].size(); ++j) {
                // First check if the cell is the same value as the first character
                // Then run dfs to find word
                if (board[i][j] == word[0] && dfs(board, word, 0, i, j)) {
                    return true;
                }
            }
        }

        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int index, int x, int y) {
        // Make sure it's not outside of bounds of the board and that the cell matches the character we're searching for
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) {
            return false;
        }
        
        // When we reach the end of the word it's true
        if (index == word.size() - 1) {
            return true;
        }
        
        bool found = false;
        
        // Keep to restore board to same as before
        char temp = board[x][y];
        
        // Mark cellls as visited
        board[x][y] = ' ';
        
        // Traverse up/down/left/right
        found = dfs(board, word, index + 1, x, y + 1) ||
        dfs(board, word, index + 1, x, y -1) ||
        dfs(board, word, index + 1, x + 1, y) ||
        dfs(board, word, index + 1, x - 1, y);
        
        // Restore character so the iteration in the main can continue
        board[x][y] = temp;
        
        return found;
        
    }
};


=====================Interviewbit repetative char allowd so dont need to use vis====================



int row[]={0,0,-1,1};
int col[]={-1,1,0,0};

int dfs(int r,int c,vector<string>&A,string &B,int index)
{
     if(index==B.size())
      return 1;
      
      for(int i=0;i<4;i++)
      {
          int x=r+row[i];
          int y=c+col[i];
          
          if(x>=0 && x<A.size() && y>=0 && y<A[0].size())
          {
              if(B[index]==A[x][y])
              {
                  if(dfs(x,y,A,B,index+1))
                     return 1;
              }
          }
      }
      
      return 0;
      
      
}

int Solution::exist(vector<string> &A, string B) {
    
    int n=A.size();
    
    if(n==0)
      return B.size()==0;
      
    int m=A[0].size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           if(A[i][j]==B[0])
           {
                 
               if(dfs(i,j,A,B,1))
                 return 1;
           }
           
        }
    }
    
   return 0;
}
