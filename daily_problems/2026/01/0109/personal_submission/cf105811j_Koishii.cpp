#include <bits/stdc++.h>
using namespace std;

bool sol() {
	int n, m; std::cin >> n >> m;

	std::vector<std::vector<std::pair<int, int>>> g1(n + 1), g2(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c; std::cin >> a >> b >> c;
		g1[a].emplace_back(b, c);
		g2[b].emplace_back(a, c);
	}

	auto uuz = [&](std::vector<std::vector<std::pair<int, int>>> &e) {
		std::vector<int> dist(n + 1, 0x3f3f3f3f);
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int,int>>> pq;
		pq.emplace(0, 1);
		dist[1] = 0;
		while (pq.size()) {
			int x = pq.top().second;
			pq.pop();
			for (auto &[y, w] : e[x]) {
				if (dist[y] > std::max(dist[x], w)) {
					dist[y] = std::max(dist[x], w);
					pq.emplace(dist[y], y);
				}
			}
		}
		return dist;
	};

	auto dist1 = uuz(g1);
	auto dist2 = uuz(g2);

	for (int i = 2; i <= n; i++) {
		if (dist1[i] < dist2[i]) {
			return false;
		}
	}
	return true;
}

void soviet() {
	if (sol()) std::cout << "YES";
	else std::cout << "NO";
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
