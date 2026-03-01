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

	int t;
	cin >> t;

	long long inf = 1e18;

	while (t --) {
		int n;
		cin >> n;

		vector<vector<pair<int, int>>> path(n);
		for (int i = 0; i < n - 1; i ++) {
			int u, v, w;
			cin >> u >> v >> w;
			u --, v --;
			path[u].emplace_back(v, w);
			path[v].emplace_back(u, w);
		}

		vector<int> dis0(n, 0);
		vector<long long> dis1(n, 0), min_dis(n, inf);

		auto dfs = [&] (auto &self, int u, int p) -> void {
			min_dis[dis0[u]] = min(min_dis[dis0[u]], dis1[u]);

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					dis0[v] = dis0[u] + 1;
					dis1[v] = dis1[u] + w;
					self(self, v, u);
				}
			}
		};

		dfs(dfs, 0, -1);

		auto dfs1 = [&] (auto &self, int u, int p) -> void {
			dis1[u] = min(dis1[u], min_dis[dis0[u]]);

			for (auto &[v, w]: path[u]) {
				if (v != p) {
					dis1[v] = dis1[u] + w;
					self(self, v, u);
				}
			}
		};

		dfs1(dfs1, 0, -1);

		for (auto &x: dis1) cout << x << ' '; cout << '\n';
	}

	return 0;
}