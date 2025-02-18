#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 n, m;
	std::cin >> n >> m;
	
	std::set<std::pair<int,int>> st;
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		if (u < v) { std::swap(u, v); }
		st.insert({u, v});
	}
	
	if (m >= n * (n - 1) / 2) {
		std::cout << "NO\n";
	} else {
		bool ok = false;
		int x = -1, y = -1;
		for (int i = 0; i < n and not ok; i++) {
			for (int j = 0; j < i and not ok; j++) {
				std::pair<int,int> p = {i, j};
				if (st.find(p) == st.end()) {
					ok = true;
					x = i;
					y = j;
				}
			}
		}
		
		std::vector<int> ans(n);
		ans[x] = 1, ans[y] = 2;
		int cur = 3;
		for (int i = 0; i < n; i++) {
			if (ans[i] == 0) {
				ans[i] = cur++;
			}
		}
		
		std::cout << "YES\n";
		for (auto& x: ans) { std::cout << x << ' '; }
		std::cout << '\n';
		ans[y] = 1;
		for (auto& x: ans) { std::cout << x << ' '; }
		std::cout << '\n';
	}
	
	return 0;
}
