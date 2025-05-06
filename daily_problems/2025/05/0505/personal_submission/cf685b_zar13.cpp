#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, q, fa[N], sz[N], zx[N];
vector<int> mp[N];
int dfs1(int u){
	int res=1;
	for(auto v:mp[u]){
		res+=dfs1(v);
	}
	return sz[u]=res;
}
void dfs2(int u){
	int tv=-1;
	for(auto v:mp[u]){
		if(tv==-1|| sz[tv]<sz[v]){
			tv=v;
		}
		dfs2(v);
	}
	if(tv==-1){
		zx[u]=u;
	}else{
		int t=zx[tv];
		while(t!=u&& sz[t]<(sz[u]+1)/2){
			t=fa[t];
		}
		zx[u]=t;
	}
}
int main() {
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int p;
		cin>>fa[i];
		mp[fa[i]].push_back(i);
	}
	dfs1(1);
	dfs2(1);
	while(q--){
		int v;
		cin>>v;
		cout<<zx[v]<<"\n";
	}
	return 0;
}
