link-->https://www.interviewbit.com/problems/capture-regions-on-board/



assume board a closed entity…where O represents opening or hole and X represent blockage… you sink board in water… water will only start filling from boundary O, 
it will penetrate deep if there is more O up,down,left,or right…whoever O got wet will remain in final matrix and those O which remained dry , 
will be transformed to X…


void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    queue<pair<int,int>>q;
    int n=A.size();
    int m=A[0].size();
 
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<A[0].size();j++)
        {
            if((i==0 ||i==n-1 || j==0 || j==m-1) && A[i][j]=='O')
           {
               A[i][j]='#';
               q.push({i,j});
               
           }
            
        }
       
    }
    
    int row[]={0,0,1,-1};
    int col[]={-1,1,0,0};
    
    while(q.empty()==false)
    {
        auto[x,y]=q.front();
        q.pop();
        
      
        for(int i=0;i<4;i++)
        {
            int r=row[i]+x;
            int c=col[i]+y;
            
            if(r>=0 && r<A.size() && c>=0 && c<A[0].size() && A[r][c]=='O')
                     {
                         A[r][c]='#';
                         q.push({r,c});
                     }
        }
        
      
    }
    
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          if(A[i][j]=='O')
             A[i][j]='X';
             
        else if(A[i][j]=='#')
          A[i][j]='O';
      }
  }
    return;
}
