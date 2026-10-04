#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	cout << fixed << setprecision(10);

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

		vector<int> dis(n, 1e9);
		dis[n - 1] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, n - 1});

		while (!pq.empty()) {
			auto [d, u] = pq.top(); pq.pop();
			if (dis[u] == d) {
				for (auto &[v, w]: path[u]) {
					if (dis[v] > dis[u] + w) {
						dis[v] = dis[u] + w;
						pq.push({dis[v], v});
					}
				}
			}
		}

		auto tmp = dis;
		sort(tmp.begin(), tmp.end());

		long double ans = n * k;
		long long cur = 0;

		for (int i = 1; i < n; i ++) {
			cur += tmp[i - 1];
			long double res = (long double)(cur + k * n) / i;
			if (res <= tmp[i]) ans = min(ans, res);
		}

		ans = min(ans, (long double)dis[0]);
		cout << ans << '\n';
	}

	return 0;
}