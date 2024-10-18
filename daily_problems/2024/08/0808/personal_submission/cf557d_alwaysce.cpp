#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	if (m == 0) {
		std::cout << 3 << ' ' << 1ll * n * (n - 1) * (n - 2) / 6 << '\n';
		return 0;
	}
	
	std::vector<std::vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	std::vector<int> color(n, -1);
	int c0, c1;
	std::function<bool(int)> dfs = [&](int u) -> bool {
		if (color[u] == 1) {
			++c1;
		} else {
			++c0;
		}
		for (auto& v: g[u]) {
			if (color[v] == -1) {
				color[v] = color[u] ^ 1;
				// u-v同色 找到了奇数环
				if (not dfs(v)) {
					return false;
				}
			} else if (color[v] == color[u]) {
				return false;
			}
		}
		return true;
	};
	
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		if (color[i] == -1) {
			c0 = 0, c1 = 0;
			color[i] = 0;
			if (not dfs(i)) {
				std::cout << 0 << ' ' << 1;
				return 0;
			}
			ans += 1ll * c0 * (c0 - 1) / 2 + 1ll * c1 * (c1 - 1) / 2;
		}
	}
	if (ans) {
		// 每个分量内部的c0/c1点集合内部 选2点连边
		std::cout << 1 << ' ' << ans << '\n';
	} else {
		// 每个连通分量只有一条边
		std::cout << 2 << ' ' << 1ll * m * (n - 2) << '\n';
	}
	return 0;
}
