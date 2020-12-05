link-->https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1#

----------------------Recursive soln (TLE)---------------------------------------------
class Solution{
    
    vector<vector<int>>nums={{1,2,3},{4,5,6},{7,8,9},{-1 ,0,-1}};
    
       unordered_map<string,int>dp;
    
    bool safe(int row,int col)
    {
        if(col<0 || col>2 || row<0 || row>3 || nums[row][col]==-1)
          return false;
  
            return true;
    }
   
   long long help(int index,int N,int x,int y)
   {
      
       if(index>N)
         return 0;
       
       if(index==N)
        return 10;
        
        static int row[]={0,0,0,-1,1};
        static int col[]={0,-1,1,0,0};
        
        long long res=0;
        for(int i=0;i<5;i++)
        {
            int r=row[i]+x;
            int c=col[i]+y;
            if(safe(r,c))
            {
                res+=help(index+1,N,r,c);
            }
        }
        
        return res;
        
   }

	public:
	long long getCount(int N)
	{
	    if(N==0)
	     return 0;
	    if(N==1)
	     return 10;
	    
	    unordered_map<int,pair<int,int>>temp;
	 
		long long res=0;
		
		for(int i=0;i<4;i++)
		{
		    for(int j=0;j<3;j++)
		    {
		        if(nums[i][j]!=-1)
		         res+=(help(1,N,i,j));
		    }
		}
		

		
		return res/10;
	
	}


};

=================================using Bottom up DP==================================

class Solution{
    
      static int row[]={0,0,0,-1,1};
    static int col[]={0,-1,1,0,0};
        
     vector<vector<int>>nums={{1,2,3},{4,5,6},{7,8,9},{-1 ,0,-1}};


	public:
	long long getCount(int N)
	{
		int n=N;
		
		if( n <= 0) 
        return 0; 
        
    if(n == 1) 
        return 10; 
        
        int count[10][n+1]; //DP memo
        
        for (i=0; i<=9; i++) 
       { 
        count[i][0] = 0; 
        count[i][1] = 1;    //count of len 0
        } 
        
        // Bottom up - Get number count of length 2, 3, 4, ... , n 
    for (k=2; k<=n; k++) 
    { 
        for (i=0; i<4; i++)  // Loop on keypad row 
        { 
            for (j=0; j<3; j++)   // Loop on keypad column 
            { 
                // Process for 0 to 9 digits 
                if (nums[i][j]!=-1) 
                { 
                    // Here we are counting the numbers starting with 
                    // digit keypad[i][j] and of length k keypad[i][j] 
                    // will become 1st digit, and we need to look for 
                    // (k-1) more digits 
                    num = nums[i][j]; 
                    count[num][k] = 0; 
  
                    // move left, up, right, down from current location 
                    // and if new location is valid, then get number 
                    // count of length (k-1) from that new digit and 
                    // add in count we found so far 
                    for (move=0; move<5; move++) 
                    { 
                        ro = i + row[move]; 
                        co = j + col[move]; 
                        if (ro >= 0 && ro <= 3 && co >=0 && co <= 2 && 
                           nums[ro][co]!=-1) 
                        { 
                            nextNum = nums[ro][co]; 
                            count[num][k] += count[nextNum][k-1]; 
                        } 
                    } 
                } 
            } 
        } 
    } 
  
    // Get count of all possible numbers of length "n" starting 
    // with digit 0, 1, 2, ..., 9 
    totalCount = 0; 
    for (i=0; i<=9; i++) 
        totalCount += count[i][n]; 
    return totalCount;
		
	}


};

