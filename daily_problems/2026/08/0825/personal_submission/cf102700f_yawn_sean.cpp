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

	int n, m, a, b, k, inf = 1e9;
	cin >> n >> m >> a >> b >> k;

	vector<vector<pair<int, int>>> path(n), rev_path(n);

	while (m --) {
		int u, v, w;
		cin >> u >> v >> w;

		path[u].emplace_back(v, w);
		rev_path[v].emplace_back(u, w);
	}

	auto shortest_path = [&] (vector<vector<pair<int, int>>> &graph, int start) -> vector<vector<int>> {
		vector<vector<int>> dis(k + 1, vector<int>(n, inf));
		dis[0][start] = 0;

		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

		pq.push({0, 0, start});

		while (!pq.empty()) {
			auto [d, layer, u] = pq.top(); pq.pop();

			if (dis[layer][u] == d) {
				for (auto &[v, w]: graph[u]) {
					if (dis[layer][v] > dis[layer][u] + w) {
						dis[layer][v] = dis[layer][u] + w;
						pq.push({dis[layer][v], layer, v});
					}
					if (layer + 1 <= k && dis[layer + 1][v] > dis[layer][u]) {
						dis[layer + 1][v] = dis[layer][u];
						pq.push({dis[layer + 1][v], layer + 1, v});
					}
				}
			}
		}

		for (int i = 1; i <= k; i ++) {
			for (int u = 0; u < n; u ++) {
				dis[i][u] = min(dis[i][u], dis[i - 1][u]);
			}
		}

		return dis;
	};

	auto solve = [&] (int start) -> vector<int> {
		auto v1 = shortest_path(path, start);
		auto v2 = shortest_path(rev_path, start);

		vector<int> ans(n, inf);
		
		for (int i = 0; i <= k; i ++) {
			for (int u = 0; u < n; u ++) {
				ans[u] = min(ans[u], v1[i][u] + v2[k - i][u]);
			}
		}

		return ans;
	};

	auto wa = solve(a), wb = solve(b);

	pair<int, int> ans = {inf, -1};

	for (int i = 0; i < n; i ++) if (i != a && i != b) ans = min(ans, {wa[i] + wb[i], i});

	if (ans.first < inf) cout << ans.second << ' ' << ans.first;
	else cout << ">:(";

	return 0;
}