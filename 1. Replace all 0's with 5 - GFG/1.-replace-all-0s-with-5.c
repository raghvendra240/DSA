// { Driver Code Starts
//Initial Template for C

#include <stdio.h>

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",convertFive(n));
    }
}
// } Driver Code Ends


//User function Template for C

int convertFive(int num) {
    // code here
    int temp = num;
    int newNum = 0;
    while(temp){
        int lastDigit = temp%10;
        temp /= 10;
        if(lastDigit == 0){
            lastDigit = 5;
        }
        
        newNum = newNum*10 + lastDigit;
    }
    int res = 0;
    while(newNum){
        res = res*10 + (newNum%10);
        newNum /= 10;
    }
    return res;
}