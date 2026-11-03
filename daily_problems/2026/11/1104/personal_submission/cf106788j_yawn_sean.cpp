#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k, inf = 1e9;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> path(n);
	vector<int> ws;

	while (m --) {
		int u, v, w;
		cin >> u >> v >> w;
		path[u].emplace_back(v, w);
		ws.emplace_back(w);
	}

	int ans = inf;

	for (auto &w0: ws) {
		vector<int> dis(n, inf);
		dis[0] = 0;

		priority_queue<pair<int, int>> pq;
		pq.push({0, 0});

		while (!pq.empty()) {
			auto [d, u] = pq.top(); pq.pop();
			d = -d;

			if (dis[u] == d) {
				for (auto &[v, w]: path[u]) {
					int nd = d + max(w, w0);
					if (dis[v] > nd) {
						dis[v] = nd;
						pq.push({-dis[v], v});
					}
				}
			}
		}

		ans = min(ans, dis[n - 1] - w0 * k);
	}

	cout << max(ans, 0);

	return 0;
}