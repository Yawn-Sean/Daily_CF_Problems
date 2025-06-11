#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		
		std::vector<std::vector<std::pair<int,int> > > adj(n);
		for (int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			--u; --v;
			adj[u].push_back({i, v});
			adj[v].push_back({i, u});
		}
		std::vector<int> ans;
		std::vector<int> sz(n, 1);
		std::function<void(int,int)> dfs = [&](int u, int p)->void{
			for (auto& pr: adj[u]) {
				int no = pr.first, v = pr.second;
				if (v == p) continue;
				dfs(v, u);
				if (sz[v] == 0) {
					ans.push_back(no);
				}
				sz[u] += sz[v];
			}
			
			if (sz[u] == 3) {
				sz[u] = 0;
			}
		};
		
		dfs(0, -1);
		if (((int)ans.size() + 1) * 3 == n) {
			std::cout << ans.size() << '\n';
			for (auto& cut: ans) {
				std::cout << cut << ' ';
			}
			std::cout << '\n';
		} else {
			std::cout << -1 << '\n';
		}
	}
		
	return 0;
}
