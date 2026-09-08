#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

typedef pair<pair<int, int>, int> node;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<vector<pair<int, int>>> path(n);

		while (m --) {
			int u, v, w;
			cin >> u >> v >> w;
			u --, v --;
			path[u].emplace_back(v, w);
			path[v].emplace_back(u, w);
		}

		vector<pair<int, int>> dis(n, {n, k});
		vector<int> dis_idx(n, n), ans(n, -1);

		dis[0] = {0, 0};
		dis_idx[0] = 0;
		ans[0] = 0;

		priority_queue<node, vector<node>, greater<node>> pq;
		pq.push({dis[0], 0});

		pair<int, int> cur_node = {0, 0};
		int cur_idx = 0;

		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();
			auto [prev_idx, edge] = cur.first;
			int u = cur.second;

			if (dis[u] == cur.first) {
				if (cur.first > cur_node) {
					cur_node = cur.first;
					cur_idx ++;
				}
				dis_idx[u] = cur_idx;

				for (auto &[v, w]: path[u]) {
					pair<int, int> ncur = {dis_idx[u], w};
					if (dis[v] > ncur) {
						dis[v] = ncur;
						ans[v] = (1ll * ans[u] * k + w) % mod;
						pq.push({dis[v], v});
					}
				}
			}
		}

		for (int i = 0; i < n; i ++) cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}