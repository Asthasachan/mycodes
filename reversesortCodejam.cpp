#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int u=1;u<=t;u++){
        int n;
        cin>>n;
        vector<int>l(n);
        for(int i=0;i<n;i++){
            cin>>l[i];
        }
        int c=0;
        for(int i=0;i<n-1;i++){
            int m=l[i],ind=i;
            for(int j=i+1;j<n;j++){
                if(l[j]<m){
                    m=l[j];
                    ind=j;
                }
            }
            c=(ind-i+1)+c;
            int h=ind;
                    //   cout<<c<<"c"<<ind<<"i"<<h<<"h"<<m<<"m";

            int s=(i+((ind-i)/2));
            for(int k=i;k<=s;k++){
                swap(l[k],l[h--]);
            }
           
            
        }
         cout<<"Case #"<<u<<": "<<c<<endl;
        
         cout<<endl;
    }
    return 0;
}
