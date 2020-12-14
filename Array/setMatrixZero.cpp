link->https://www.interviewbit.com/problems/set-matrix-zeros/


//--sc O(n+m) and TC O(nm)
void Solution::setZeroes(vector<vector<int> > &A) {
  
    
   
    int n=A.size();
    int m=A[0].size();
     vector<int>row(n,1);
    vector<int>col(m,1);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==0)
              {
                  row[i]=0;
                  col[j]=0;
              }
        }
    }
    
    
    for(int c=0;c<m;c++)
    {
        
        if(col[c]==0)
        { for(int i=0;i<n;i++)
        {
            A[i][c]=0;
        }
        }
    }
    
    
     for(int k=0;k<n;k++)
     {
         if(row[k]==0)
       {   for(int i=0;i<m;i++)
        {
            A[k][i]=0;
        }}
     }
    
    return;
    
    
}

===============================O(1} space=========================



class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            int rownum = matrix.size();
            if (rownum == 0)  return;
            int colnum = matrix[0].size();
            if (colnum == 0)  return;

            bool hasZeroFirstRow = false, hasZeroFirstColumn = false;

            // Does first row have zero?
            for (int j = 0; j < colnum; ++j) {
                if (matrix[0][j] == 0) {
                    hasZeroFirstRow = true;
                    break;
                }
            }

            // Does first column have zero?
            for (int i = 0; i < rownum; ++i) {
                if (matrix[i][0] == 0) {
                    hasZeroFirstColumn = true;
                    break;
                }
            }

            // find zeroes and store the info in first row and column
            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

            // set zeroes except the first row and column
            for (int i = 1; i < rownum; ++i) {
                for (int j = 1; j < colnum; ++j) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
                }
            }

            // set zeroes for first row and column if needed
            if (hasZeroFirstRow) {
                for (int j = 0; j < colnum; ++j) {
                    matrix[0][j] = 0;
                }
            }
            if (hasZeroFirstColumn) {
                for (int i = 0; i < rownum; ++i) {
                    matrix[i][0] = 0;
                }
            }
        }
};




