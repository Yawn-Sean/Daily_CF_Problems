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

	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<int>> path(n + m);

	for (int u = 0; u < n; u ++) {
		int k;
		cin >> k;
		while (k --) {
			int v; cin >> v; v --;
			path[u].emplace_back(n + v);
			path[n + v].emplace_back(u);
		}
	}

	vector<vector<int>> dis(m, vector<int>(n + m, -1));

	for (int x = 0; x < m; x ++) {
		dis[x][n + x] = 0;
		queue<int> q; q.push(n + x);

		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &v: path[u]) {
				if (dis[x][v] == -1) {
					dis[x][v] = dis[x][u] + 1;
					q.push(v);
				}
			}
		}
	}

	int inf = 1e6;

	while (q --) {
		int u, v;
		cin >> u >> v;
		u --, v --;

		int ans = inf;

		for (int i = 0; i < m; i ++) {
			if (dis[i][u] != -1 && dis[i][v] != -1) {
				ans = min(ans, dis[i][u] + dis[i][v]);
			}
		}

		cout << (ans < inf ? ans / 2 - 1 : -1) << '\n';
	}

	return 0;
}