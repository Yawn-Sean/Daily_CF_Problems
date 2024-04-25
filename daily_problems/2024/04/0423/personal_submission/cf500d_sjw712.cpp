#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
void solve(){
	int n, q;
	cin >> n;
	vector<vector<pii>> g(n + 1);
	vector<tuple<int, int, int>> edges;
	vector<int> fa(n + 1), sz(n + 1);
	for(int i = 1; i < n; i ++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
		edges.push_back({a, b, c});
	}
	auto dfs = [&](auto self, int u, int father)->void{
		sz[u] = 1;
		for(auto &[j, _]: g[u]){
			if(j == father) continue;
			fa[j] = u;
			self(self, j, u);
			sz[u] += sz[j];
		}
	};
	dfs(dfs, 1, -1);
	double ans = 0;
	for(auto &[a, b, c]: edges){
		if(fa[b] == a) swap(a, b);
		if(sz[a] == 1){
			ans += c * (n - sz[a]) * (n - sz[a] - 1);
		}
		else if(sz[b] == 1){
			ans += c * sz[a] * (sz[a] - 1);
		}
		else{
			ans += c * (n - sz[a]) * sz[a] * (sz[a] - 1);
			ans += c * (n - sz[a]) * (n - sz[a] - 1) * sz[a];
		}
	}
	double k = n * (n - 1) * (n - 2) / 6;
	cin >> q;
	while(q --){
		int r, w;
		cin >> r >> w;
		r --;
		auto &[a, b, c] = edges[r];
		if(sz[a] == 1){
			ans += (w - c) * (n - sz[a]) * (n - sz[a] - 1);
		}
		else if(sz[b] == 1){
			ans += (w - c) * sz[a] * (sz[a] - 1);
		}
		else{
			ans += (w - c) * (n - sz[a]) * sz[a] * (sz[a] - 1);
			ans += (w - c) * (n - sz[a]) * (n - sz[a] - 1) * sz[a];
		}
		c = w;
		cout << fixed << setprecision(10) << ans / k << '\n';
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --){
		solve();
	}
}
