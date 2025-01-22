#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
vector<int> g[N];
bool flg[N];
int n, k;
LL ans;
LL dfs(int u, int fa){
	LL res=0;
	if(flg[u]) res++;
	for(int v:g[u]){
		if(v==fa) continue;
		res+=dfs(v, u);
	}
	ans+=min(res, k-res);
	return res;
}
int main(){
	cin>>n>>k;
	k*=2;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		flg[x]=1;
	}
	for(int i=1;i<n;i++){
		int u, v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	cout<<ans;
	return 0;
}
