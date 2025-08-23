
#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
using i128 = __int128;

void solve() {
	int n;
	std::cin >> n;
	std::vector e(n, std::vector<int>());
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		v--;
		u--;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	std::vector<i64> a(n, 1), b(n, 1);
	auto dfs = [&](this auto && self, int u, int fu)->void {
		std::vector<int> f;
		for (auto v : e[u]) {
			if (v == fu) {
				continue;
			}
			self(v, u);
			f.push_back(b[v]);
			// std::cout << b[v] << endl;
		}
		std::sort(f.begin(), f.end(), std::greater<int>());
		if (f.size() == 0) {
			return ;
		}
		b[u] += f[0];
		a[u] += f[0];
		if (f.size() > 1) {
			a[u] += f[1];
			b[u] += f.size() - 1;
		}
		if (f.size() > 2) {
			a[u] += f.size() - 2;
		}
		if (fu != -1) {
			a[u]++;
		}
		return ;
	};
	dfs(0, -1);
	int ans = std::max(*std::max_element(a.begin(), a.end()), *std::max_element(b.begin(), b.end()));
	std::cout << ans << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
