#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> g(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	int D; std::cin >> D;
	std::vector<int> d(D + 1);
	std::multiset<int> se;
	for (int i = 1; i <= D; i++) {
		std::cin >> d[i];
	}
	for (int i = 1; i <= D; i++) {
		int x; std::cin >> x;
		se.insert(x);
	}

	std::vector<long long> dist(n + 1, 1e18);
	{
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
		pq.emplace(0, 1);
		dist[1] = 0;
		while (pq.size()) {
			auto [distance, x] = pq.top();
			pq.pop();
			if (distance > dist[x]) continue;
			for (const auto &[y, w] : g[x]) {
				if (dist[y] > std::max<long long>(dist[x], w)) {
					dist[y] = std::max<long long>(dist[x], w);
					pq.emplace(dist[y], y);
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= D; i++) {
		if (d[i] == 1) {
			ans++;
			continue;
		}
		auto it = se.lower_bound(dist[d[i]]);
		if (it != se.end()) {
			ans++;
			se.erase(it);
		}
	}
	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
