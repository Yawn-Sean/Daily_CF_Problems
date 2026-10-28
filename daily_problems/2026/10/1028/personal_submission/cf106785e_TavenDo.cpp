#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define fi first 
#define se second 
using LL=long long;
using PLL=pair<LL,LL>;

//
const LL MOD=998244353;
void solve() {
	int n,m;
	cin>>n>>m;
	vector<string>adj(n+1);
	for(int i=1;i<=n;++i){
		cin>>adj[i];
		adj[i]="!"+adj[i];
	}
	if(adj[1][1]=='#' or adj[n][m]=='#'){
		cout<<0<<endl;
		return;
	}
	vector<vector<PLL>>dp(n+1,vector<PLL>(m+1));  //fi->D   se->R
	dp[1][1].fi=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(adj[i][j]=='#' or (i==1 and j==1)){
				continue;
			}
			dp[i][j].fi=(dp[i-1][j].fi+dp[i][j].fi)%MOD;
			dp[i][j].se=(dp[i][j-1].fi+dp[i][j-1].se)%MOD;
			if(adj[i][j-1]=='#'){
				dp[i][j].fi=(dp[i-1][j].se+dp[i][j].fi)%MOD;
			}
		}
	}
	cout<<(dp[n][m].fi+dp[n][m].se)%MOD<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}