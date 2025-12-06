#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void soviet() {
	int n, m; std::cin >> n >> m;
	std::vector<int> vis(n + 1);
	std::vector<std::vector<int>> path(n + 1);

	while (m--) {
		int x, y; std::cin >> x >> y;
		path[x].emplace_back(y);
		path[y].emplace_back(x);
		vis[x] = vis[y] = 1;
	}

	int pt = 0;
	std::vector<int> to_check;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) {
			vis[i] = ++pt;
			to_check.emplace_back(i);
		}
	}

	std::vector<int> dp(pt + 1, 0);
	dp[vis[1]] = 1;
	for (int i = 1; i <= n; i++) {
		long long total = 0;
		for (auto &x : dp) total = (total + x) % mod;
		if (i >= 2) std::cout << total << ' ';
		std::vector<int> ndp(pt + 1, total);
		ndp[0] = 1LL * (n - pt) * total % mod;

		for (auto &u: to_check) {
			for (auto &v: path[u]) {
				ndp[vis[v]] = (ndp[vis[v]] - dp[vis[u]] + mod) % mod;
			}
		}

		for (int j = 0; j <= pt; j++) {
			ndp[j] = (ndp[j] - dp[j] + mod) % mod;
		}
		dp = ndp;
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
