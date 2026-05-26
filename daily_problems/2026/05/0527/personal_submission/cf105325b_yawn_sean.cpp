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

	int t, inf = 1e9;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<vector<pair<int, int>>> path(n);
		
		while (m --) {
			int u, v, w;
			cin >> u >> v >> w;
			path[u].emplace_back(v, w);
		}

		vector<vector<int>> dis(n, vector<int>(n, inf));

		for (int i = 0; i < n; i ++) dis[i][0] = 0;

		for (int i = n - 1; i > 0; i --) {
			for (int u = 0; u < n; u ++) {
				for (auto &[v, w]: path[u]) {
					dis[i - 1][v] = min(dis[i - 1][v], dis[i][u] + i * w);
				}
			}
		}

		for (int i = 1; i < n; i ++) {
			cout << (dis[0][i] < inf ? dis[0][i] : -1) << " \n"[i == n - 1];
		}
	}

	return 0;
}