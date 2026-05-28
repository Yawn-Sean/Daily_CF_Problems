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

	int n, m, g;
	cin >> n >> m >> g;

	if (g > 2) cout << 0;
	else {
		vector<vector<int>> path(n);
		while (m --) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<int> dis(n, -1);
		dis[0] = 0;

		bool flg = true;

		auto dfs = [&] (auto &self, int u) -> void {
			for (auto &v: path[u]) {
				if (dis[v] == -1) {
					dis[v] = dis[u] ^ 1;
					self(self, v);
				}
				else if (dis[u] == dis[v]) {
					flg = false;
				}
			}
		};

		dfs(dfs, 0);

		if (flg && dis[n - 1]) cout << 1;
		else cout << 0;
	}

	return 0;
}