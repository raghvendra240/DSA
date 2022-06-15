// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method*/
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int sumA = 0;
        int sumB = 0;
        for(int i = 0 ;i < l1 ; i++) sumA += A[i];
        for(int i=0 ;i < l2 ; i++)sumB +=B[i];
        int res = max(sumA,sumB);
        int tempRes = 0;
        int tempSumA = 0;
        int tempSumB = 0;
        int index1 = 0;
        int index2 =0;
        for(; index1 < l1 && index2 < l2 ; ){
            if(A[index1] < B[index2]){
             tempSumA+=A[index1++];
            }else if(B[index2] < A[index1]){
                tempSumB+=B[index2++];
            }

            if(index1 < l1 && index2 < l2 && A[index1] == B[index2]){
                 tempSumA+=A[index1++];
                 tempSumB+=B[index2++];
                 tempRes += max(tempSumA, tempSumB);
                 tempSumA = 0;
                 tempSumB = 0;
            }
        }
        while(index1 < l1){
            tempSumA+=A[index1++];
        }
        while(index2 < l2){
            tempSumB+=B[index2++];
        }
        tempRes += max(tempSumA, tempSumB);
        return max(res, tempRes);
        }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        fflush(stdin);
        int a[N],b[M];
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<M;i++)
            cin>>b[i];
        Solution obj;
        int result = obj.max_path_sum(a,b,N,M);
        cout<<result<<endl;
    }
}

  // } Driver Code Ends