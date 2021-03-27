#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int u=1;u<=t;u++){
		int n,c;
		cin>>n>>c;
		vector<int>s(n);
		for(int i=1;i<=n;i++){
			s[i-1]=i;
		}
		int f=0;
		if(c<n-1){
			f=1;
		}
		if(f==0){
			vector<int>l;
			int tot=0,cou=1;
			for(int i=n-1;i>0;i--){
				cou=cou+1;
				if((tot+cou+i-1)>=c){
					int r=c-tot-i+1;
					l.push_back(r);
					for(int j=0;j<i-1;j++){
					    l.push_back(1);	
					}
					tot=c;
					break;
				}
				tot=tot+cou;
				l.push_back(cou);
			}
			if(tot<c){
				f=1;
			}
			if(l.size()<=0){
				f=1;
			}
			if(f==0){
			int leng=l.size();
			for(int o=0;o<leng;o++){
				int h=s.size()-(o+2);
				int sp=h+l[o];
				int y=sp-1;
				for(int v=h;v<=(h+(((sp-1)-h)/2));v++){
					swap(s[v],s[y]);
					y--;
				}
			}
		}
		}
		if(f==1){
			cout<<"Case #"<<u<<": IMPOSSIBLE"<<endl;
 
		}
		else{
			cout<<"Case #"<<u<<": ";
			for(int g=0;g<n;g++){
				cout<<s[g]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
