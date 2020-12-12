https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;

	while(t--)
	{
	    int n;
	    cin>>n;
	   
	    string s="1";
	    
	    for(int i=2;i<=n;i++)
	    {
	        int carry=0;
	        
	        for(int j=s.length()-1;j>=0;j--)
	        {
	            int temp=(s[j]-'0')*i+carry;
	            int x=temp%10;
	            s[j]='0'+x;
	            carry=temp/10;
	        }
	        
	        if(carry!=0)
	        {
	            s=to_string(carry)+s;
	        }
	    }
	    
	    cout<<s<<endl;
	}
	return 0;
}
