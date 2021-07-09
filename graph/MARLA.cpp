//https://www.codechef.com/problems/MARLA
#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[1004][1004];
int v[1004][1004];
int dfs(int x,int y,int num){
	int a=0;
	if(x>n||y>m||x<1||y<1){
		return 0;
	}
	v[x][y]=1;
	if(s[x+1][y]==num && !v[x+1][y]){
		a=a+1+dfs(x+1,y,num);
	}
		if(s[x-1][y]==num && !v[x-1][y]){
		a=a+1+dfs(x-1,y,num);
	}
		if(s[x][y+1]==num && !v[x][y+1]){
		a=a+1+dfs(x,y+1,num);
	}
		if(s[x][y-1]==num && !v[x][y-1]){
		a=a+1+dfs(x,y-1,num);
	}
	return a;
}
int main(){
	int a=0;
	cin>>n>>m;
	int ind=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s[i][j];
		}
	}
	int maxs=0,minum=INT_MAX;
		for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!v[i][j]){
				int temp=1+dfs(i,j,s[i][j]);
				if(temp>maxs){
					maxs=temp;
					minum=s[i][j];
				}
				else if(temp==maxs){
					minum=min(minum,s[i][j]);
				}
			}
		}}
		cout<<minum<<" "<<maxs;
}
