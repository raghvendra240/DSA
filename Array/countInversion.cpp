https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#

long long int merge(long long arr[],long long left,long long right,long long mid)
{
    long long n=(mid-left+1);
    long long m=(right-mid);
    
    long long arr1[n];
    long long arr2[m];
    

    for(int i=0;i<n;i++)
    {
        arr1[i]=arr[i+left];
    }
    for(int i=0;i<m;i++)
    {
        arr2[i]=arr[mid+1+i];
    }
    long long int res=0;
    int k=left;
    int i=0,j=0;
    
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
             arr[k]=arr2[j];
             res+=(n-i);
            j++;
            k++;
        }
    }
    
    while(i<n)
    {
        arr[k]=arr1[i];
            i++;
            k++;
    }
    
    while(j<m)
    {
         arr[k]=arr2[j];
            j++;
            k++;
    }
    
    return res;
}

long long int ms(long long arr[],long long left,long long right)
{
    if(left>=right)
      return 0;
      
     long long int res=0;
     long long mid= left +(right-left)/2;
     
     res+=ms(arr,left,mid);
     res+=ms(arr,mid+1,right);
     
     res+=merge(arr,left,right,mid);
     
     return res;
}

long long int inversionCount(long long arr[], long long N)
{
   return ms(arr,0,N-1);
}
