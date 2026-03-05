#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, m; std::cin >> n >> m;

	std::vector<long long> a(n + 1);
	for (int i = 1; i <= n; i++) std::cin >> a[i];

	std::vector<std::vector<std::pair<long long, int>>> e(n + 1);
	while (m--) {
		int x, y, w; std::cin >> x >> y >> w;
		e[x].emplace_back(y, w);
		e[y].emplace_back(x, w);
	}

	auto uuz = [&](int ss, const std::vector<std::vector<std::pair<long long, int>>> &e){
		std::vector<long long> dist(n + 1, 1e18);
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
		pq.emplace(0, ss);
		dist[ss] = 0;
		while (pq.size()) {
			auto [distance, x] = pq.top();
			pq.pop();
			if (distance > dist[x]) continue;
			for (const auto &[y, w] : e[x]) {
				if (dist[y] >= dist[x] + w && dist[x] + w <= a[y]) {
					dist[y] = dist[x] + w;
					pq.emplace(dist[y], y);
				}
			}
		}
		return dist;
	};

	for (int i = 1; i <= n; i++) {
		e[0].emplace_back(i, a[i]);
	}

	auto dist1 = uuz(0, e);

	for (int i = 1; i <= n; i++) a[i] = std::min(a[i], dist1[i]);

	auto dist2 = uuz(1, e);

	std::cout << (dist2[n] !=   1e18 ? "YES" : "NO") << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
