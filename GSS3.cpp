//https://www.spoj.com/problems/GSS3/
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long int n,m,a,x,y;
	cin>>n;
	vector<long long int>s(n+1);
	s[0]=0;
	for(long long int i=1;i<=n;i++){
		cin>>s[i];
	}
	cin>>m;
	for(long long int i=0;i<m;i++){
		cin>>a>>x>>y;
		if(a==0){
			s[x]=y;
		}
		if(a==1){
			long long int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (long long int i = x; i<=y ; i++)
    {
        max_ending_here = max_ending_here + s[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    cout<<max_so_far<<endl;
		}
	}
}
 
