#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, m, xor_op;
		cin >> n >> m >> xor_op;

		vector<array<int, 3>> edges(m);
		for (auto &[u, v, w]: edges) {
			cin >> u >> v >> w;
			u --, v --;
		}

		sort(edges.begin(), edges.end(), [&] (array<int, 3> x, array<int, 3> y) {return x[2] < y[2];});

		long long ans = 0;
		atcoder::dsu uf(n);

		vector<vector<pair<int, int>>> path(n);

		for (auto &[u, v, w]: edges) {
			if (uf.merge(u, v)) {
				ans += w;
				path[u].emplace_back(v, w);
				path[v].emplace_back(u, w);
			}
		}

		vector<vector<int>> nth_parent(18, vector<int>(n, -1));
		vector<vector<int>> nth_edge(18, vector<int>(n, 0));
		vector<int> depth(n, 0);

		auto dfs = [&] (auto &self, int u, int p) -> void {
			for (auto &[v, w]: path[u]) {
				if (v != p) {
					nth_parent[0][v] = u;
					nth_edge[0][v] = w;
					depth[v] = depth[u] + 1;
					self(self, v, u);
				}
			}
		};

		dfs(dfs, 0, -1);

		int diff = (m == n - 1 ? xor_op : 0);

		for (int i = 0; i < 17; i ++) {
			for (int u = 0; u < n; u ++) {
				if (nth_parent[i][u] != -1) {
					nth_parent[i + 1][u] = nth_parent[i][nth_parent[i][u]];
					nth_edge[i + 1][u] = max(nth_edge[i][u], nth_edge[i][nth_parent[i][u]]);
				}
			}
		}

		for (auto &[u, v, w]: edges) {
			if (depth[u] > depth[v]) swap(u, v);

			int cur = 0;
			int d = depth[v] - depth[u];

			while (d) {
				int x = d & -d;
				int bit = __builtin_ctz(x);
				cur = max(cur, nth_edge[bit][v]);
				v = nth_parent[bit][v];
				d -= x;
			}

			if (u != v) {
				for (int i = 17; i >= 0; i --) {
					if (nth_parent[i][u] != nth_parent[i][v]) {
						cur = max(cur, nth_edge[i][u]);
						u = nth_parent[i][u];
						cur = max(cur, nth_edge[i][v]);
						v = nth_parent[i][v];
					}
				}

				cur = max(cur, nth_edge[0][u]);
				cur = max(cur, nth_edge[0][v]);
			}

			diff = min(diff, (w ^ xor_op) - cur);
		}

		cout << ans + diff;
	}

	return 0;
}