#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#include "atcoder/modint.hpp"

using namespace std;
using mint = atcoder::static_modint<998244353>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<vector<int>> path(n);
		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<mint> dp(n), rev_dp(n), parent(n, -1);

		auto dfs1 = [&] (auto &self, int u, int p) -> void {
			dp[u] = 1;
			parent[u] = p;

			vector<int> tmp;
			for (auto &v: path[u]) {
				if (v != p) {
					tmp.emplace_back(v);
				}
			}

			dp[u] = 2;
			for (auto &v: tmp) {
				self(self, v, u);
				dp[u] *= dp[v];
			}

			if (tmp.size() == 3) dp[u] = 0;
			else if (tmp.empty()) dp[u] = 1;
		};

		dfs1(dfs1, 0, -1);

		auto dfs2 = [&] (auto &self, int u, int p) -> void {
			if (u == 0) {
				if (path[u].size() == 1) {
					for (auto &v: path[u]) {
						rev_dp[v] = rev_dp[u];
						self(self, v, u);
					}
				}
				else {
					for (auto &x: path[u]) {
						rev_dp[x] = 2;
						for (auto &y: path[u]) {
							if (y != x) {
								rev_dp[x] *= dp[y];
							}
						}
						self(self, x, u);
					}
				}
			}
			else {
				vector<int> tmp;
				for (auto &v: path[u]) {
					if (v != p) {
						tmp.emplace_back(v);
					}
				}

				for (auto &x: tmp) {
					rev_dp[x] = 2 * rev_dp[u];
					for (auto &y: tmp) {
						if (y != x) {
							rev_dp[x] *= dp[y];
						}
					}
					self(self, x, u);
				}
			}
		};
	
		rev_dp[0] = 1;
		dfs2(dfs2, 0, -1);

		mint ans = 0;

		for (int i = 0; i < n; i ++) {
			if (path[i].size() <= 2) {
				mint res = 2 * rev_dp[i];
				for (auto &j: path[i]) {
					if (parent[j] == i) {
						res *= dp[j];
					}
				}
				ans += res;
			}
		}

		cout << ans.val() << '\n';
	}

	return 0;
}