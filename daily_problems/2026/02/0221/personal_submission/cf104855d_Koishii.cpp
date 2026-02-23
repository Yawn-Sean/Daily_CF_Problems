#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, m; std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> e(n + 1);
	while (m--) {
		int x, y, c; std::cin >> x >> y >> c;
		e[x].emplace_back(y, c);
	}
    
	std::vector<std::set<int>> se(n + 1);
	std::vector<int> ans(n + 1);
	std::queue<std::pair<int, int>> q;
	q.emplace(1, 0);
	while (q.size()) {
		auto [x, x_c] = q.front();
		ans[x] = 1;
		q.pop();
		for (auto &[y, y_c] : e[x]) {
			if (se[y].find(y_c) != se[y].end() || se[y].size() >= 2) continue;
			if (x_c != y_c || se[x].size() >= 2) {
				se[y].insert(y_c);
				q.emplace(y, y_c);
			}
		}
	}
    
	for (int i = 1; i <= n; i++) {
		if (ans[i]) std::cout << i << ' ';
	}
	std::cout << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
