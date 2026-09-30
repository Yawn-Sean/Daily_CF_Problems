#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<array<int, 3>>> path(n);

	while (m --) {
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		u --, v --;
		path[u].push_back({v, t, h});
		path[v].push_back({u, t, h});
	}

	vector<int> latest_time(n, -1);
	latest_time[0] = (int)1e9;

	priority_queue<pair<int, int>> pq;
	pq.push({latest_time[0], 0});

	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (latest_time[u] == d) {
			for (auto &[v, t, h]: path[u]) {
				int nd = min(d, h) - t;
				if (nd > latest_time[v]) {
					latest_time[v] = nd;
					pq.push({nd, v});
				}
			}
		}
	}

	for (auto &x: latest_time) cout << (x >= 0);

	return 0;
}