#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m, s, t;
	std::cin >> n >> m >> s >> t;
	--s; --t;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	auto bfs = [&](int start) {
		std::vector<int> vis(n, 0);
		vis[start] = 1;
		std::vector<int> dis(n, 1e9);
		dis[start] = 0;
		
		std::queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int k = (int)q.size();
			while (k--) {
				int u = q.front();
				q.pop();
				
				for (auto& v: adj[u]) {
					if (!vis[v]) {
						dis[v] = dis[u] + 1;
						vis[v] = 1;
						q.push(v);
					}
				}	
			}
		}
		
		return dis;
	};
	
	std::vector<int> sd = bfs(s);
	std::vector<int> td = bfs(t);

	int ans = 0;
	for (int u = 0; u < n; u++) {
		for (int v = u + 1; v < n; v++) {
			if (u != v) {
				// std::cout << "From s:" << s << ", to u:" << u << ", dis=" << sd[u] << '\n'; 
				// std::cout << "From t:" << t << ", to v:" << v << ", dis=" << td[v] << '\n'; 
				if ((sd[u] + 1 + td[v] < sd[t]) or (sd[v] + 1 + td[u] < sd[t])) {
					;
				} else {
					ans++;
				}
			}
		}
	}
	std::cout << ans - m << '\n';
	return 0;
}
