#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n;
	std::cin >> n;
	int m;
	std::cin >> m;
	std::vector e(n + 1, std::vector<std::pair<int, i64>>());
	for (int i = 0; i < m; i++) {
		int u, v;
		i64 w;
		std::cin >> u >> v >> w;
		e[u].emplace_back(std::make_pair(v, w));
		e[v].emplace_back(std::make_pair(u, w));
	}
	std::priority_queue<std::tuple<i64, int, int>>q1;
	std::vector<i64> vis(n + 1, -1);
	std::unordered_map < int, std::unordered_map<int, int >> b;
	std::vector<int> fu(n + 1, 0);
	q1.push({0, 1, 0});
	while (!q1.empty()) {
		auto [x, y, z] = q1.top();
		q1.pop();
		if (vis[y] != -1) {
			continue;
		}
		if (y == n) {
			fu[y] = z;
			int t = y;
			while (t != 0) {
				b[t][fu[t]] = 1;
				b[fu[t]][t] = 1;
				t = fu[t];
			}
		}
		vis[y] = -x;
		fu[y] = z;
		for (auto [v, w1] : e[y]) {
			q1.push({x - w1, v, y});
		}
	}
	if (vis[n] == -1) {
		std::cout << -1 << endl;
		return ;
	}
	std::vector<i64> vis1(n + 1, -1);
	std::priority_queue<std::pair<i64, int>>q;
	q.push({0, n});
	while (!q.empty()) {
		auto [x, y] = q.top();
		q.pop();
		if (vis1[y] != -1) {
			continue;
		}
		vis1[y] = -x;
		for (auto [v, w1] : e[y]) {
			q.push({x - w1, v});
		}
	}
	i64 ans = 4e18;
	for (int i = 1; i <= n; i++) {
		for (auto &[j, w] : e[i]) {
			if (vis[i] != -1 && vis1[j] != -1 && b[i].find(j) == b[i].end())
				ans = std::min(ans, vis[n] + vis[i] + vis1[j] + w);
		}
	}
	if (ans == 4e18) {
		std::cout << -1 << endl;
	}
	else {
		std::cout << ans << endl;
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
