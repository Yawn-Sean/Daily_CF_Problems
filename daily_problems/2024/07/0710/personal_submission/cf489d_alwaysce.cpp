#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> adj(n);
		
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
	}
	
	i64 ans = 0;
	std::vector<i64> cnt(n);
	for (int u = 0; u < n; u++) {
		for (auto& v: adj[u]) {
			for (auto& w: adj[v]) {
				cnt[w]++;
			}
			
		}
		for (int v = 0; v < n; v++) {
			if (v != u) {
				ans += cnt[v] * (cnt[v] - 1) / 2;
			}
			cnt[v] = 0;
		}
	}
	std::cout << ans << '\n';
	
	return 0;
}
