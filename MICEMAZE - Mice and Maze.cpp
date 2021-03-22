//https://www.spoj.com/problems/LABYR1/
#include<bits/stdc++.h>
using namespace std;
long long minDistance(vector<long long>dist,vector<bool>sptSet,long long V) 
{ 
    long long min = INT_MAX, min_index; 
  
    for (long long v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
void dijikstra(vector<vector<long long>>s,long long src,long long n,long long t){
vector<long long>d(n,INT_MAX);
d[src]=0;
vector<bool>seen(n,false);
for(long long i=0;i<n-1;i++){
	 long long u = minDistance(d,seen,n); 
	 seen[u]=true;
	 for(long long v=0;v<n;v++){
	 	if(!seen[v] && s[u][v]!=INT_MAX && d[u]!=INT_MAX && d[u]+s[u][v]<d[v]){
	 		d[v]=d[u]+s[u][v];
	 	}
	 }
}
long long c=0;
for(long long i=0;i<n;i++){
	if(d[i]<=t){
		c++;
	}
}
cout<<c;
return;
}
int main(){
	long long  n,e,t,m;
	cin>>n;
	cin>>e;
	cin>>t;
	cin>>m;
	vector<vector<long long >>s(n,vector<long long >(n,INT_MAX));
	for(long long i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		s[b-1][a-1]=c;
	}
	dijikstra(s,e-1,n,t);
	return 0;
}
