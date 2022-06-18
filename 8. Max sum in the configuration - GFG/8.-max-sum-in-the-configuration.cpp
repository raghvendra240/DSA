// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
    int withoutRotation = 0;
    int elementSum = 0;
    for(int i = 0 ; i < N ; i++){
        withoutRotation += A[i]*i;
        elementSum += A[i];
    }
    int res = withoutRotation;
    for(int rotationIndex = 1 ; rotationIndex < N ; rotationIndex++ ){
        withoutRotation = withoutRotation - elementSum + (A[rotationIndex-1]*(N));
        res =  max(res,withoutRotation);
    }

    return res;
}