#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> path(n);
	vector<int> parent(n);

	for (int i = 1; i <= n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(i, v);
		path[v].emplace_back(i, u);
	}

	vector<int> dp_down(n, 0), dp_up(n, 0);

	auto dfs1 = [&] (auto &self, int u, int p) -> void {
		parent[u] = p;
		for (auto &[i, v]: path[u]) {
			if (v != p) {
				self(self, v, u);
				dp_down[u] = max(dp_down[u], dp_down[v] + 1);
			}
		}
	};

	auto dfs2 = [&] (auto &self, int u, int p) -> void {
		int v1 = dp_up[u], v2 = 0;
		for (auto &[i, v]: path[u]) {
			if (v != p) {
				int val = dp_down[v] + 1;
				if (val > v1) swap(v1, v2), v1 = val;
				else if (val > v2) v2 = val;
			}
		}

		for (auto &[i, v]: path[u]) {
			if (v != p) {
				int val = dp_down[v] + 1;
				if (val == v1) dp_up[v] = v2 + 1;
				else dp_up[v] = v1 + 1;
				self(self, v, u);
			}
		}
	};

	dfs1(dfs1, 0, -1);
	dfs2(dfs2, 0, -1);

	int ans = n, chosen = -1;

	for (int i = 1; i < n; i ++) {
		int res = max(dp_down[i], dp_up[i] - 1);
		if (res < ans) ans = res, chosen = i;
	}

	vector<int> chosen_edge(n);

	auto dfs = [&] (auto &self, int u, int p) -> void {
		for (auto &[i, v]: path[u]) {
			if (v != p) {
				chosen_edge[v] = i;
				self(self, v, u);
			}
		}
	};

	for (auto &[i, v]: path[chosen]) {
		if (v == parent[chosen]) {
			chosen_edge[v] = i;
			chosen_edge[chosen] = i;
			dfs(dfs, v, chosen);
			dfs(dfs, chosen, v);
		}
	}

	cout << ans << '\n';
	for (auto &x: chosen_edge) cout << x << ' ';
 
	return 0;
}