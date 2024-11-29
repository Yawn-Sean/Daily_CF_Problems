#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e5+5;
vector<int> g[N];
int n, x, y, s[N], zs, ztag;
bool flag;
int dfs(int u, int fa, int tg){
	bool f=0;
	if(u==x){
		if(tg==0) tg=1, f=1;
		else flag=1, ztag=2;
	}
	if(u==y){
		if(tg==0) tg=2, f=1;
		else flag=1, ztag=1;
	}
	int res=1;
	for(auto v:g[u]){
		if(v==fa) continue;
		int vs=dfs(v, u, tg);
		if(f&& flag){
			zs=vs;
			flag=0;
			continue;
		}
		res+=vs;
	}
	return s[u]=res;
}
int main(){
	cin>>n>>x>>y;
	int a, b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, -1, 0);
	LL ans=1LL*n*(n-1);
	if(ztag==0) ans-=1LL*s[y]*s[x];
	if(ztag==1) ans-=1LL*s[y]*(n-zs);
	if(ztag==2) ans-=1LL*s[x]*(n-zs);
	cout<<ans;
	return 0;
}
