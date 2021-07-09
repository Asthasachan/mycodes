//https://www.spoj.com/problems/BUGLIFE/
#include <bits/stdc++.h>
using namespace std;
bool isbug(	vector<vector<int>>& s,int k,int n,vector<int>& col){
    if(k==0){
	col[k]=1;
    }
	queue<int>q;
	q.push(k);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(s[u][u]==1){
			return false;
		}
		for(int v=0;v<n;v++){
			if(s[u][v]==1 && col[v]==-1){
				col[v]=1-col[u];
				q.push(v);
			}
			else if(s[u][v]==1 && col[u]==col[v]){
				return false;
			}
		}
	}
		return true;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int u=0;u<t;u++){
		int n,m;
		cin>>n>>m;
		vector<vector<int>>s(n,vector<int>(n,0));
 
		for(int i=0;i<m;i++){
 
			int a,b;
			cin>>a>>b;
			s[a-1][b-1]=1;
			s[b-1][a-1]=1;
		}
			vector<int>col(n,-1);
			int f=0;
		for(int i=0;i<n;i++){
			if(col[i]==-1){
			isbug(s,i,n,col)?f=0:f=1;
			}
			if(f==1){
				break;
			}
		}
		if(f==0){cout<<"Scenario #"<<u+1<<":\n"<<"No suspicious bugs found!\n";
		}
		else if(f==1){
		cout<<"Scenario #"<<u+1<<":\n"<<"Suspicious bugs found!\n";
		}
 
	}
	return 0;
} 
