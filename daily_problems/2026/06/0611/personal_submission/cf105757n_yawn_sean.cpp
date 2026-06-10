#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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
		int n;
		cin >> n;

		vector<vector<int>> path(n);
		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<int> parent(n);

		auto dfs = [&] (auto &self, int u, int p) -> void {
			parent[u] = p;

			for (auto &v: path[u]) {
				if (v != p) {
					self(self, v, u);
				}
			}
		};

		dfs(dfs, 0, -1);

		vector<int> vis(n, 0), degs(n, 0);
		vis[0] = 1;

		int ans = 0;
		bool flg = true;

		for (int i = 1; i < n; i ++) {
			int cur = i;
			while (!vis[cur]) {
				vis[cur] = 1;
				degs[cur] ++;
				degs[parent[cur]] ++;
				cur = parent[cur];
				if (degs[cur] > 2)
					flg = false;
			}
			if (flg) ans = i;
		}

		cout << ans + 1;
		for (int i = 2; i < n; i ++) cout << ' ' << (i <= path[0].size());
		cout << '\n';
	}

	return 0;
}