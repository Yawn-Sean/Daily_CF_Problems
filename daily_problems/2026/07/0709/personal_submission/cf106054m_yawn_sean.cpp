#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> path(n);

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> dis(n, -1), que = {0};
	dis[0] = 0;

	for (int i = 0; i < que.size(); i ++) {
		int u = que[i];
		for (auto &v: path[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				que.emplace_back(v);
			}
		}
	}

	if (dis[1] == -1) cout << 0;
	else {
		int mod = 998244353, bound = n + k;

		vector<vector<int>> combs(bound, vector<int>(bound, 0));

		for (int i = 0; i < bound; i ++) {
			combs[i][0] = 1;
			combs[i][i] = 1;

			for (int j = 1; j < i; j ++) {
				combs[i][j] = (combs[i - 1][j] + combs[i - 1][j - 1]) % mod;
			}
		}

		auto comb = [&] (int x, int y) -> int {
			if (x < 0 || y < 0 || y > x) return 0;
			return combs[x][y];
		};

		vector<vector<int>> dp(k, vector<int>(n, 0));
		dp[0][0] = 1;

		for (int i = 0; i < k; i ++) {
			for (auto &u: que) {
				if (dp[i][u] == 0) continue;

				for (auto &v: path[u]) {
					int ni = dis[u] + i + 1 - dis[v];
					if (ni < k) {
						dp[ni][v] += dp[i][u];
						dp[ni][v] %= mod;
					}
				}
			}
		}

		int ans = 0, days = (dis[1] - 1) / k + 1;

		for (int i = 0; i < k; i ++) {
			if (dis[1] + i <= days * k) {
				int res = 0;

				for (int cnt = 0; cnt <= days; cnt ++) {
					int resid = dis[1] + i - cnt * k;
					if (cnt % 2 == 0)
						res += 1ll * comb(resid - 1, days - 1) * comb(days, cnt) % mod;
					else
						res += mod - 1ll * comb(resid - 1, days - 1) * comb(days, cnt) % mod;
					res %= mod;
				}

				ans += 1ll * res * dp[i][1] % mod;
				ans %= mod;
			}
		}

		cout << ans;
	}

	return 0;
}