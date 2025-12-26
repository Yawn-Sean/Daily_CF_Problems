#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> e(n * 3 + 1);

	auto add = [&](int u, int v, int w) {
		e[u].push_back({v, w});
	};

	for (int i = 1; i <= m; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		add(u, v, w);
		add(u, v + n, w / 2);
		add(u + n, v + 2 * n, w / 2);
		add(u + 2 * n, v + 2 * n, w);
	}

	auto uuz = [&](){
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
		std::vector<long long> dist(3 * n + 1, 1e18);
		std::vector<int> vis(3 * n + 1);
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
		return min({dist[n], dist[2 * n], dist[3 * n]});
	};
	std::cout << uuz();
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
