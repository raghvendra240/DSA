
Sol#1

int celebrity(vector<vector<int> >& M, int n) {
        
        int knowsAnyone[n]={false};
        int totalKnownPersons[n]={0};

        for(int i=0;i<n;i++)
        {
          bool knows=false;

          for(int j=0;j<n;j++)
          {
                if(M[i][j]==1)
                {
                  knows=true;
                  totalKnownPersons[j]++;
                }

                
          }
          
          knowsAnyone[i]=knows;

        }

        for(int i=0;i<n;i++)
        {
          if(knowsAnyone[i]==false && totalKnownPersons[i]==n-1)
             return i;
        }

        return -1;
    }
    
    
    ===========
    Sol#2 stack based O(n) space
    
    int findCelebrity(int n) 
{ 
    // Handle trivial  
    // case of size = 2 
    stack<int> s; 
  
    // Celebrity 
    int C;  
  
    // Push everybody to stack 
    for (int i = 0; i < n; i++) 
        s.push(i); 
  
    // Extract top 2 
    int A = s.top(); 
    s.pop(); 
    int B = s.top(); 
    s.pop(); 
  
    // Find a potential celebrity 
    while (s.size() > 1) 
    { 
        if (knows(A, B)) 
        { 
            A = s.top(); 
            s.pop(); 
        } 
        else
        { 
            B = s.top(); 
            s.pop(); 
        } 
    } 
    // If there are only two people  
    // and there is no 
    // potential candicate 
    if(s.empty()) 
        return -1; 
    
    
    // Potential candidate? 
    C = s.top(); 
    s.pop(); 
  
    // Last candidate was not  
    // examined, it leads one  
    // excess comparison (optimize) 
    if (knows(C, B)) 
        C = B; 
  
    if (knows(C, A)) 
        C = A; 
  
    // Check if C is actually 
    // a celebrity or not 
    for (int i = 0; i < n; i++) 
    { 
        // If any person doesn't  
        // know 'a' or 'a' doesn't  
        // know any person, return -1 
        if ( (i != C) && 
                (knows(C, i) ||  
                 !knows(i, C)) ) 
            return -1; 
    } 
  
    return C; 
} 
  
  
  ======================
  SOl#3 o(1) space using two pointers
  
   bool knows(int a,int b,vector<vector<int>>&M)
    {
        return M[a][b];
    }
    
    public:
     int celebrity(vector<vector<int> >& M, int n) {
        
        int a = 0; 
    int b = n - 1; 
  
    // Keep moving while  
    // the two pointers 
    // don't become same.  
    while (a < b) 
    { 
        if (knows(a, b,M)) 
            a++; 
        else
            b--; 
    } 
  
    // Check if a is actually 
    // a celebrity or not 
    for (int i = 0; i < n; i++) 
    { 
        // If any person doesn't  
        // know 'a' or 'a' doesn't 
        // know any person, return -1 
        if ( (i != a) && 
                (knows(a, i,M) ||  
                !knows(i, a,M)) ) 
            return -1; 
    } 
  
    return a; 

    }

