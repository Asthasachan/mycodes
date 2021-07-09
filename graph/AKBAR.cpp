//https://www.spoj.com/problems/AKBAR/
#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int>s[],vector<int>d,vector<int>& k,int start,int& f){
    if(k[start]!=-1){
        f=1;
        return;
    }
    queue<int>q;
    q.push(start);
    k[start]=d[start];
    int v[10000004]={0};
    while(!q.empty()){
        int u=q.front();
        if(v[u]==0){
            v[u]=1;
        }
        q.pop();
        if(k[u]>0){
            for(int i=0;i<s[u].size();i++){
            
                if(v[s[u][i]]==0){
              
                if(d[s[u][i]]!=-1){
                    f=1;
                    return;
                }
                if(k[s[u][i]]!=-1){
                    f=1;
                    return;
                }
                q.push(s[u][i]);
                k[s[u][i]]=k[u]-1;
                v[s[u][i]]=1;
                }
            }
            k[u]=0;
        }
        
    }
}
int main() {
	// your code goes here
	int t; cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        vector<int>s[n];
        int c1,c2;
        for(int i=0;i<a;i++){
            cin>>c1>>c2;
            s[c1-1].push_back(c2-1);
            s[c2-1].push_back(c1-1);
        }
        int s1;
        vector<int>d(n,-1);
        vector<int>k(n,-1);
        for(int i=0;i<b;i++){
            cin>>c1>>s1;
            d[c1-1]=s1;
            if(s1==0){
                k[c1-1]=s1;
            }
        }
        int f=0;
        for(int i=0;i<n;i++){
            if(d[i]>0){
                bfs(s,d,k,i,f);
                if(f==1){
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(k[i]==-1){
                f=1;
                break;
            }
        }
        if(f==0){
            cout<<"Yes"<<endl;
        }
        if(f==1){
            cout<<"No"<<endl;
        }
    }
	return 0;
}
