#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	i64 n;
	std::cin >> n;
	
	std::vector<std::vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	// 原有的d>=2的站点距离会减小1
	// d(u,v) => d(u,v)/2(偶数) 或者是 (d(u,v)+1)/2(奇数)
	// 问题: 奇数的点对有多少?
	i64 ans = 0, cnt = 0;
	std::vector<int> size(n,1), colors(n,0);
	std::function<void(int,int)> dfs = [&](int u, int fa){
		cnt += colors[u];
		for (auto& v: adj[u]) {
			if (v != fa) {
				colors[v] = colors[u] ^ 1;
				dfs(v, u);	
				size[u] += size[v];	
			}
		}
	};
	
	dfs(0, -1);
	
	ans = cnt * (n - cnt);
	// d(u,v)可以通过边的贡献来快速求
	for (auto& sub: size) {
		ans += sub * (n - sub);
	}
	std::cout << ans / 2 << '\n';
	
	return 0;
}
