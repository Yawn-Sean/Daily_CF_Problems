#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n; std::cin >> n;
	std::vector<std::string> s(n + 1);
	std::vector<std::vector<int>> e(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		s[i] = ' ' + s[i];
		for (int j = 1; j <= n; j++) {
			if (s[i][j] == '1' || s[i][j] == '?') {
				e[i].emplace_back(j);
			}
		}
	}
	std::queue<int> q;
	q.push(1);
	std::vector<int> vis(n + 1);
	vis[1] = 1;
	std::vector<std::pair<int, int>> ans;
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto &y : e[x]) {
			if (!vis[y]) {
				vis[y] = 1;
				ans.push_back({x, y});
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			std::cout << "No" << '\n';
			return;
		}
	}
	std::cout << "Yes\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		auto &[x, y] = ans[i];
		std::cout << x << ' ' << y << '\n';
	}
	std::cout << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
