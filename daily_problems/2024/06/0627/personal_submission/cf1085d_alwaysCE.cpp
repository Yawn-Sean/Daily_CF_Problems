#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 100000007;
i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, s;
	std::cin >> n >> s;
	std::vector<std::vector<int>> adj(n, std::vector<int>());
	std::vector<int> deg(n);
	
	for (int i = 1; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		a--;b--;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	// 把权重均匀的分配在连接叶子的边上
	int leaf = 0;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 1) {
			leaf++;
		}
	}
	
	double ans = (double)s / leaf;
	std::cout << std::fixed << std::setprecision(9) << ans * 2.0 << '\n';
	return 0;
}
