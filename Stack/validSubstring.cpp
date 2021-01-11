
Method #1 using Stack O(N) space

 int findMaxLen(string s) {
        
        int res=0;
        stack<int>st;
        
     st.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
             st.push(i);
             
             else
             {
                 st.pop();
                 
                 if(st.empty()==false)
                  res=max(res,i-st.top());
                  
                  else
                   st.push(i); 
             }
        }
        return res;
        // code here
    }
    
    =================================
    Method #2 using two pointer O(N) psace
    
    int solve(string s, int n) 
{ 
  
    // Variables for left and right counter. 
    // maxlength to store the maximum length found so far 
    int left = 0, right = 0, maxlength = 0; 
  
    // Iterating the string from left to right 
    for (int i = 0; i < n; i++)  
    { 
        // If "(" is encountered, 
        // then left counter is incremented 
        // else right counter is incremented 
        if (s[i] == '(') 
            left++; 
        else
            right++; 
  
        // Whenever left is equal to right, it signifies 
        // that the subsequence is valid and 
        if (left == right) 
            maxlength = max(maxlength, 2 * right); 
  
        // Reseting the counters when the subsequence 
        // becomes invalid 
        else if (right > left) 
            left = right = 0; 
    } 
  
    left = right = 0; 
  
    // Iterating the string from right to left 
    for (int i = n - 1; i >= 0; i--) { 
  
        // If "(" is encountered, 
        // then left counter is incremented 
        // else right counter is incremented 
        if (s[i] == '(') 
            left++; 
        else
            right++; 
  
        // Whenever left is equal to right, it signifies 
        // that the subsequence is valid and 
        if (left == right) 
            maxlength = max(maxlength, 2 * left); 
  
        // Reseting the counters when the subsequence 
        // becomes invalid 
        else if (left > right) 
            left = right = 0; 
    } 
    return maxlength; 
} 
