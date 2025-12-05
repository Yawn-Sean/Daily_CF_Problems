#include <bits/stdc++.h>
using namespace std;


void soviet() {
	int n, m; std::cin >> n >> m;
	long long v; std::cin >> v;
	std::string s; std::cin >> s; s = ' ' + s;

	std::vector<std::array<int, 6>> op(m + 1);
	for (int i = 1; i <= m; i++) {
		auto &[a, x, b, y, c, z] = op[i];
		std::cin >> a >> x >> b >> y >> c >> z;
	}

	std::vector<long double> cost(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') cost[i] = 1;
	}

	for (int _ = 1; _ <= n; _++) {
		for (int i = 1; i <= m; i++) {
			auto &[a, x, b, y, c, z] = op[i];
			if (cost[x] < 0 || cost[y] < 0) continue;
			if (cost[z] < 0) cost[z] = (a * cost[x] + b * cost[y]) / c;
			else cost[z] = std::min(cost[z], (a * cost[x] + b * cost[y]) / c);
		}
	}

	if (cost[1] <= 0) std::cout << 0 << '\n';
	else std::cout << v / cost[1] << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cout << std::fixed << std::setprecision(12);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
