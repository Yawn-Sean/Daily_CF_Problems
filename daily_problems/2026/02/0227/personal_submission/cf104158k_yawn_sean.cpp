#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> path(n);
	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<pair<int, int>> routes(m);
	for (auto &[u, v]: routes) {
		cin >> u >> v;
		u --, v --;
	}

	vector<int> parent(n, -1), depth(n, 0);
	auto dfs = [&] (auto &self, int u, int p) -> void {
		for (auto &v: path[u]) {
			if (v != p) {
				parent[v] = u;
				depth[v] = depth[u] + 1;
				self(self, v, u); 
			}
		}
	};

	dfs(dfs, 0, -1);

	vector<vector<int>> nth_parent(20, vector<int>(n, -1));
	nth_parent[0] = parent;

	for (int i = 0; i < 19; i ++) {
		for (int j = 0; j < n; j ++) {
			if (nth_parent[i][j] != -1) {
				nth_parent[i + 1][j] = nth_parent[i][nth_parent[i][j]];
			}
		}
	}

	auto lca = [&] (int u, int v) -> int {
		if (depth[u] > depth[v]) swap(u, v);

		int d = depth[v] - depth[u];
		for (int i = 0; i < 20; i ++) {
			if (d >> i & 1) {
				v = nth_parent[i][v];
			}
		}

		if (u == v) return u;

		for (int i = 19; i >= 0; i --) {
			if (nth_parent[i][u] != nth_parent[i][v]) {
				u = nth_parent[i][u];
				v = nth_parent[i][v];
			}
		}

		return parent[u];
	};

	long long ans = 0;
	vector<int> ls(m), cnt(n, 0);

	for (int i = 0; i < m; i ++) {
		auto [u, v] = routes[i];
		ls[i] = lca(u, v);
		cnt[ls[i]] ++;
		ans -= cnt[ls[i]];
	}

	auto dfs1 = [&] (auto &self, int u, int p) -> void {
		for (auto &v: path[u]) {
			if (v != p) {
				cnt[v] += cnt[u];
				self(self, v, u); 
			}
		}
	};

	dfs1(dfs1, 0, -1);

	for (int i = 0; i < m; i ++) {
		auto [u, v] = routes[i];
		ans += cnt[u] + cnt[v] - cnt[ls[i]];
		if (ls[i]) ans -= cnt[parent[ls[i]]];
	}

	cout << ans;

	return 0;
}