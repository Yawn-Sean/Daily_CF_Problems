#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, m, k; std::cin >> n >> m >> k;
	std::vector<std::vector<std::pair<int, int>>> e(n + k + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, c; std::cin >> u >> v >> c;
		e[u].push_back({v, c});
		e[v].push_back({u, c});
	}

	for (int i = 1; i <= n; i++) {
		int t; std::cin >> t;
		while (t--) {
			int u, c; std::cin >> u >> c;
			e[i].push_back({u + n, c});
			e[u + n].push_back({i, 0});
		}
	}

	auto uuz = [&]() -> long long {
		std::vector<long long> dist(n + k + 1, 1e18);
		std::vector<int> vis(n + k + 1);
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
		pq.push({0, 1});
		dist[1] = 0;
		while (pq.size()) {
			int x = pq.top().second;
			pq.pop();
			if (vis[x]) continue;
			else vis[x] = 1;
			for (auto &[y, w]: e[x]) {
				if (dist[y] > dist[x] + w) {
					dist[y] = dist[x] + w;
					pq.push({dist[y], y});
				}
			}
		}
		return dist[n];
	};

	std::cout << uuz();
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
