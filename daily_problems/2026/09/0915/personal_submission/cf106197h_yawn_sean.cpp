#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<int> out_deg(n, 0);
		vector<vector<int>> rev_path(n);

		while (m --) {
			int u, v;
			cin >> u >> v;
			u --, v --;

			out_deg[u] ++;
			rev_path[v].emplace_back(u);
		}

		vector<int> vis(n, 0), cur_deg(n, 0);
		vis[n - 1] = 1;

		auto dfs = [&] (auto &self, int u) -> void {
			for (auto &v: rev_path[u]) {
				cur_deg[v] ++;
				if (cur_deg[v] * 2 > out_deg[v] && !vis[v]) {
					vis[v] = 1;
					self(self, v);
				}
			}
		};

		dfs(dfs, n - 1);

		if (vis[0]) cout << "-1\n";
		else {
			vector<pair<int, int>> edges;

			for (int u = 0; u < n; u ++) {
				for (auto &v: rev_path[u]) {
					if (!vis[v] && vis[u]) {
						edges.emplace_back(v, u);
					}
				}
			}

			cout << edges.size() << '\n';
			for (auto &[u, v]: edges) cout << u + 1 << ' ' << v + 1 << '\n';
		}
	}

	return 0;
}