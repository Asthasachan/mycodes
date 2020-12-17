#include <bits/stdc++.h>
#define ll long long int
using namespace std;
bool isvalid(string&s){
	if(s.length()>3){
		return false;
	}
	if(s.front()=='0' && s.length()>1){
		return false;
	}
	ll val=stoll(s);
	return val>=0 && val<=255;
}
void findip(string&s,vector<string>&res){
	for(ll i=1;i<=3 && i<s.length();i++){
		string first=s.substr(0,i);
		if(isvalid(first)){
				for(ll j=1;j<=3 && j+i<s.length();j++){
					string second=s.substr(i,j);
					if(isvalid(second)){
							for(ll k=1;k<=3 && i+j+k<s.length();k++){
								string third=s.substr(i+j,k);
								string fourth=s.substr(i+j+k);
								if(isvalid(third) && isvalid(fourth)){
									res.push_back(first+"."+second+"."+third+"."+fourth);
								}
							}
					}
				}
		}
	}
}
int main() {
	// your code goes here
	string s;
	cin>>s;
	vector<string>res;
	findip(s,res);
	for(auto i:res){
		cout<<i<<endl;
	}
  if(res.size()==0){
		cout<<"No valid ip address";
	}
	return 0;
}


/*
example input->
21121111135
output->
21.121.111.135
211.21.111.135
211.211.11.135
211.211.111.35
*/
