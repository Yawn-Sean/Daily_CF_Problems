#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<int> b(n + 1);
	std::vector<std::vector<int>> p(100005);
	for (int i = 1; i <= n; i++) {
		std::cin >> b[i];
		p[b[i]].emplace_back(i);
	}

	int ans = 1e9;
	for (int i = 1; i <= 100000; i++) {
		if (p[i].empty()) continue;
		int now = 0;
		p[i].emplace_back(p[i].front() + n);
		for (int j = 1; j < p[i].size(); j++) {
			now = std::max(now, p[i][j] - p[i][j - 1] - 1);
		}
		ans = std::min(ans, n + now);
	}
	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
