#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int u=1;u<=t;u++){
        int x,y;
        cin>>x>>y;
        string s;
        getline(cin,s);
        int c=0,f=0;
        string l,k;
        for(int i=1;i<s.length();i++)
        {   k=s[i];
            if(f==0){
               if(k=="C" || k=="J"){
                   l=s[i];
                   f=1;
               } 
            }
            else{
                if(k=="J" && l=="C"){
                    c=c+x;
                    l=s[i];
                }
                else if(k=="C" && l=="J"){
                    c=c+y;
                    l=s[i];
                }
            }
           
        }
         cout<<"Case #"<<u<<": "<<c<<endl;
    }
}
