//链接：https://codeforces.com/problemset/problem/1671/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX=2e5+10;
int g[MAX];
ll ans[MAX];
int k;
int n,m;

ll f(){
	int big=g[0];
	ll ans=0;
	for(int i=1;i<n;i++){
		ans+=abs(g[i]-g[i-1]);
		big=max(big,g[i]);
	}
	int v=min(g[0]-1,g[n-1]-1);                //得考虑在开头 或 结尾+ 
	int u=min(abs(g[0]-m),abs(g[n-1]-m));
	for(int i=1;i<n;i++){
		v=min(v,abs(g[i]-1)+abs(g[i-1]-1)-abs(g[i]-g[i-1]));
		u=min(u,abs(g[i]-m)+abs(g[i-1]-m)-abs(g[i]-g[i-1]));
	}
	ans+=v;
	if(big<m) ans+=u;                         //数组max >=m 添加增益为0                 
	return ans;
} 

int main(){
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>n>>m;
		for(int j=0;j<n;j++) cin>>g[j];
		ans[i]=f();
	}
	
	for(int i=0;i<k;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
} 
