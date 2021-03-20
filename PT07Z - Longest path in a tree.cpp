#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>s[],vector<int>&d,int n,int& start){
	for(int i=0;i<n;i++){
		d[i]=-1;
	}
	d[start]=0;
	queue<int>q;
	q.push(start);
	int v,u;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=0;i<s[u].size();i++){
			v=s[u][i];
			if(d[v]==-1){
				q.push(v);
				d[v]=d[u]+1;
			}
		}
	}
}
int main(){
	int n,a,b;
	cin>>n;
	vector<int>s[n];
	while(cin>>a>>b){
		s[a-1].push_back(b-1);
		s[b-1].push_back(a-1);
	}
	vector<int>d(n);
		int m=-1,index=0;
	dfs(s,d,n,index);

	for(int i=0;i<n;i++){
		if(d[i]>m){
			m=d[i];
			index=i;
		}
	}
	dfs(s,d,n,index);
	m=-1;
	for(int i=0;i<n;i++){
		if(d[i]>m){
			m=d[i];
			
		}
	}
	cout<<m;
}
