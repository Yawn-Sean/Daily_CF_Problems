#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
		
	int n, m, h, t;
	std::cin >> n >> m >> h >> t;
	
	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<int> no(n);
	
	std::function<bool(int,int)> check = [&](int u, int v) -> bool {
		if ((int)adj[u].size() <= h or (int)adj[v].size() <= t) {
			return false;
		}
		int cnt = 0;
		no[u] = no[v] = -1;
		for (auto &x: adj[u]) {
			if (!no[x]) { ++cnt; }
			no[x] |= 1;	
		}
		
		for (auto &y: adj[v]) {
			if (!no[y]) { ++cnt; }
			no[y] |= 2;
		}
		
		if (cnt >= h + t) {
			std::vector<int> tu, tv;
			for (auto& x: adj[u]) {
				if (h and no[x] == 1) {
					h--;
					tu.push_back(x);
				}
			}
			for (auto& y: adj[v]) {
				if (t and no[y] == 2) {
					t--;
					tv.push_back(y);
				}
			}
			for (auto& x: adj[u]) {
				if (no[x] == 3) {
					if (h) {
						h--;
						tu.push_back(x);
					} else if (t) {
						t--;
						tv.push_back(x);
					}
				}
			}
			
			std::cout << "YES\n";
			std::cout << u + 1 << ' ' << v + 1 << '\n';
			for (auto& x: tu) {
				std::cout << x + 1 << ' ';
			}
			std::cout << '\n';
			for (auto& y: tv) {
				std::cout << y + 1 << ' ';
			}
			std::cout << '\n';
			return true;
		}
		
		for (auto& x: adj[u]) {
			no[x] = 0;
		}
		for (auto& y: adj[v]) {
			no[y] = 0;
		}
		return false;
	};
	
	for (int u = 0; u < n; u++) {
		for (auto& v: adj[u]) {
			if (check(u, v)) {
				return 0;
			}
		}
	}
	std::cout << "NO\n";
	return 0;
}
