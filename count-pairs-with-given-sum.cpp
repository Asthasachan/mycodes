class Solution{   
public:
    int getPairsCount(int a[], int n, int k) {
        // code here
        
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]>m){
                m=a[i];
            }
        }
        int s[m+1]={0};
        for(int i=0;i<n;i++){
            s[a[i]]++;
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(k-a[i]>a[i] && k-a[i]<=m){
                if(s[k-a[i]]>0)
            c=c+s[k-a[i]];
              
            }
            else if(k-a[i]==a[i] && s[k-a[i]]>0 ){
                c=c+((s[a[i]]*(s[a[i]]-1))/2);
                s[a[i]]=0;
            }
        }
        return c;
        
    }
};
//https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
//hashing
