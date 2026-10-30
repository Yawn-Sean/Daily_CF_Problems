#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())
const int inf = 1e9;

//
struct info{
	int u,v,w;
};
const int MXN=8e3+325;
void solve() {
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>a(k+1);
	for(int i=1;i<=k;++i){
		cin>>a[i];
	}
	vector<int>dp(n+1,-1);   //dp[i] min(i->1)
	vector<vector<int>>adj(n+1);
	int u,v;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dp[1]=0;
	queue<info>wk;
	vector<vector<int>>fa(n+1);
	for(auto nxt:adj[1]){
		wk.push({1,nxt,1});
	}
	vector<int>vis;
	vis.push_back(1);
	while(!wk.empty()){
		auto [cu,cv,cw]=wk.front();
		wk.pop();
		if(dp[cv]==-1){
			vis.push_back(cv);
			fa[cv].push_back(cu);
			dp[cv]=cw;
			for(auto nxt:adj[cv]){
				if(nxt==cu){
					continue;
				}
				wk.push({cv,nxt,cw+1});
			}
		}else if(dp[cv]==cw){
			fa[cv].push_back(cu);
		}
	}
	int ans=0;
	vector<bitset<MXN+1>>res(n+1);
	for(int i=1;i<=k;++i){
		res[a[i]][i]=1;
	}
	bitset<MXN+1>msk;
	msk[0]=1;
	for(int i=k+1;i<=MXN;++i){
		msk[i]=1;
	}
	for(int i=sz(vis)-1;i>=0;--i){
		int C=vis[i];
		res[C]|=msk;
		if(res[C].all()){
			cout<<dp[C]<<endl;
			return;
		}
		for(auto nxt:fa[C]){
			res[nxt]|=res[C];
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}