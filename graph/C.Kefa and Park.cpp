#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>s[],vector<int>&d,int n,int& start,int m){
 
	queue<int>q;
	q.push(start);
	set<int>seen;
	int v,u;
	while(!q.empty()){
		u=q.front();
		q.pop();
		if(seen.find(u)==seen.end()){
		seen.insert(u);
		}
		for(int i=0;i<s[u].size();i++){
			v=s[u][i];
				if(seen.find(v)==seen.end()){
				q.push(v);
				if(d[v]==1 && d[u]>0){
				d[v]=d[u]+d[v];
				}
				else if(d[u]>m){
					d[v]=d[v]+d[u];
				}
				}
		}
	}
}
int main(){
 
	int n,m,a,b;
	cin>>n>>m;
	vector<int>d(n);
	for(int i=0;i<n;i++){
		cin>>d[i];
	}
	vector<int>s[n];
	for(int i=0;i<n-1;i++){
		cin>>a>>b;
		s[a-1].push_back(b-1);
			s[b-1].push_back(a-1);
	}
 
		int c=0,index=0;
	bfs(s,d,n,index,m);
 
	for(int i=1;i<n;i++){
		if(s[i].size()==1){
			if(d[i]<=m){
				c++;
				
			}
		}
	}
 
	cout<<c<<endl;
	return 0;
} 
//codeforces
//https://codeforces.com/problemset/problem/580/C
