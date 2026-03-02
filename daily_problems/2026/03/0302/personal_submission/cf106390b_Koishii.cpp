#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<std::vector<std::pair<int, long long>>> e(n + 1); 
	for (int i = 1; i < n; i++) {
		int u, v, w; std::cin >> u >> v >> w;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}

	std::vector<long long> dep(n + 1), dist(n + 1), dx(n + 1, 1e18), save(n + 1);
	auto bfs = [&]() -> void {
		std::queue<int> q;
		q.emplace(1);
		dx[0] = 0;
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (const auto &[y, w] : e[x]) {
				if (dist[y] || y == 1) continue;
				dist[y] = dist[x] + w;
				dep[y] = dep[x] + 1;
				dx[dep[y]] = std::min(dx[dep[y]], dist[y]);
				q.emplace(y);
			}
		}
	};

	auto bfs2 = [&]() -> void {
		std::queue<int> q;
		q.emplace(1);
		std::vector<int> vis(n + 1);
		while (q.size()) {
			int x = q.front();
			q.pop();
			for (const auto &[y, w]: e[x]) {
				if (vis[y] || y == 1) continue;
				vis[y] = 1;
				save[y] = std::max(save[x], dist[y] - dx[dep[y]]);
				q.emplace(y);
			}
		}
	};

	bfs();
	bfs2();

	for (int i = 1; i <= n; i++) {
		std::cout << dist[i] - save[i] << ' ';
	}
	std::cout << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
