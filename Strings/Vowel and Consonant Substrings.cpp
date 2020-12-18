https://www.interviewbit.com/problems/vowel-and-consonant-substrings/

======Method On and On space

//using suffuix array


bool help(char x)
{
    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
       return true;
       
       return false;
}

int Solution::solve(string A) {
    
    int n=A.size();
   
    int v[n],c[n];
    
    v[n-1]=0;
    c[n-1]=0;
    if(help(A[n-1]))
      v[n-1]=1;
     else
      c[n-1]=1;
    
    for(int i=n-2;i>=0;i--)
    {
        c[i]=c[i+1];
        v[i]=v[i+1];
        
            if(help(A[i]))
             v[i]++;
      else
      c[i]++;
    }
    
    int res=0;
    
    for(int i=0;i<n-1;i++)
    {
        if(help(A[i]))
        {
            res= (res+c[i])%1000000007;
        }
        else
         res=  (res+v[i])%1000000007;
    }
    
    return res%1000000007;
    
}

====================O(1) sapce

int Solution::solve(string A) {
int mod = pow(10,9) +7;
int a=0,b=0,c=0,d=0;
int sum=0;
for(int i=0;i<A.length();i++){
if(A[i]==‘a’ || A[i]==‘e’ || A[i]==‘i’ || A[i]==‘o’ || A[i]==‘u’ ){
a++;
sum+=b;
}
else {b++;
sum+=a;
}
sum%=mod;
}

return sum;
}
