link-->https://www.geeksforgeeks.org/stepping-numbers/
   https://www.interviewbit.com/problems/stepping-numbers/
   
   
   
   vector<int> Solution::stepnum(int A, int B) {
    

int a=A;
int b=B;
vector<int>res;
if(a==0) res.push_back(0);

    queue <int> q;
    for(int i=1;i<=9;++i) q.push(i);
    
    while(q.front()<=b)
    {
        int num = q.front(); q.pop();
        if(num>=a) res.push_back(num);  //inside range
        
        int MSBdigit=num%10;
        if(MSBdigit>0) 
        q.push(num*10 + MSBdigit-1);
        if(MSBdigit<9)
        q.push(num*10 + MSBdigit+1);
    }
    
    return res;
}
