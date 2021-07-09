//https://www.spoj.com/problems/LABYR1/
#include<bits/stdc++.h>
using namespace std;
int ans;
int mR[4]={0,-1,0,1};
int mC[4]={-1,0,1,0};
int n,m;
char M[2009][2009];
bool visited[2009][2009];
int max(int a,int b){return a>b?a:b;}
int dfs(int i,int j)
{
int tr,tc,p;
int m1,m2,b;
m1=m2=-1;
visited[i][j]=true;
for(p=0;p<4;p++)
{
tr=i+mR[p];
tc=j+mC[p];
if(tr>=0 && tr<n && tc>=0 && tc<m && visited[tr][tc]==false && M[tr][tc]=='.')
{
b=dfs(tr,tc);
if(b>=m1)
{
m2=m1;
m1=b;
}
else if(b>m2)m2=b;
}
}
ans=max(ans,m1+m2+2);
return m1+1;
}
int main(void)
{
int t,i,j;
bool flag;
cin>>t;
while(t--)
{
flag=false;
cin>>m>>n;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
cin>>M[i][j];
visited[i][j]=false;
}
}
ans=0;
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
if(M[i][j]=='.')
{
flag=true;
break;
}
}
if(flag)break;
}
dfs(i,j);
printf("Maximum rope length is %d.\n",ans);
}
}
