class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
  //exect time=0.27
  // use merge sort to count no. of count inversions using merge function and save it .
    long long merge(long long arr[],long long l,long long m,long long r)
{   long long p=0;
    long long n1 = m - l + 1;
    long long n2 = r - m;
    long long L[n1], R[n2];
    for (long long i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (long long j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    long long i = 0;
    long long j = 0;
    long long k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
          //c++;
            arr[k] = L[i];
            i++;
        }
        else {
             arr[k] = R[j];
           p=p+((sizeof(L) / sizeof(L[0]))-i);
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return p;
}
void mergeSort(long long arr[],long long l,long long r,long long&c){
    if(l>=r){
        return;
    }
    long long m =l+ (r-l)/2;
    mergeSort(arr,l,m,c);
    mergeSort(arr,m+1,r,c);
    c=merge(arr,l,m,r)+c;
   
    
}
 
    long long  inversionCount(long long a[], long long n)
    {
        // Your Code Here
        
        long long  c=0;
       mergeSort(a,0, n-1,c);
        return c;
    }

};
