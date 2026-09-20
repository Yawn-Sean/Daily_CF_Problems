#include <bits/stdc++.h>
using namespace std;

struct DSU {
	int n;
	std::vector<int> p;

	DSU(int _n): n(_n) {
		p.resize(n + 1);
		for (int i = 0; i <= n; i++) p[i] = i;
	}

	int find(int x) {
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		p[x] = y;
	}
};

struct Edge {
	int x, y;
	long long w;

	bool operator < (const Edge& e2) const {
		return w < e2.w;
	}
};

void soviet() {
	int n, m; std::cin >> n >> m;

	std::vector<Edge> e;
	for (int i = 1; i <= m; i++) {
		int x, y;
		long long w;
		std::cin >> x >> y >> w;
		e.emplace_back(Edge{x, y, w});
	}

	std::sort(e.begin(), e.end());



	DSU d(n);
	long long cost = 0;
	std::vector<std::vector<int>> g(n + 1);
	for (auto& [x, y, w] : e) {

		if (d.find(x) == d.find(y)) continue;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
		d.merge(x, y);
		cost += w << 1;
	}
	std::cout << cost << '\n';
	std::vector<int> ans;

	auto dfs = [&](auto&& self, int x, int fa) -> void {
		ans.emplace_back(x);
		for (auto y : g[x]) {
			if (y == fa) continue;
			self(self, y, x);
			ans.emplace_back(x);
		}
	};
	dfs(dfs, 1, 0);

	std::cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x << ' ';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
