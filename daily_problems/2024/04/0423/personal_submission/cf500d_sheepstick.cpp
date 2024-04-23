#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;

	vector<vector<array<int,3>>> adj(n + 1);
	vector<i64> cost(n), len(n);
	for (int i = 1; i < n; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w, i});
		adj[v].push_back({u, w, i});
		len[i] = w;
	}

	vector<i64> c3(n + 1);
	for (int i = 3; i <= n; i++){
		c3[i] = 1LL * i * (i - 1) * (i - 2) / 6;
	}


	double tot = 0;
	vector<int> pa(n + 1, -1);
	auto dfs = [&](auto self, int u, int p) -> int {
		int cnt = 1;
		for (auto &[v, w, idx] : adj[u]) {
			if (v != p){
				cnt += self(self, v, u);
			}
			else pa[u] = idx;
		}
		if (u != 1) {
			cost[pa[u]] = c3[n] - c3[cnt] - c3[n - cnt];
			tot += 2.0 * cost[pa[u]] / c3[n] * len[pa[u]];
		}
		return cnt;
	};
	dfs(dfs, 1, -1);

	int q; cin >> q;
	while(q--){
		int r, w; cin >> r >> w;
		int delta = len[r] - w;
		len[r] = w;

		tot -= 2.0 * cost[r] / c3[n] * delta;
		cout << fixed << setprecision(10) << (double) tot << "\n";

	}


}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}