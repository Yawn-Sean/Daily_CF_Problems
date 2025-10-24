#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	if (n & 1 || n > 2005) return cout << "impossible", 0;

	vector<vector<int>> path(n, vector<int>(n, 1));

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u][v] = 0;
		path[v][u] = 0;
	}

	for (int i = 0; i < n; i ++)
		path[i][i] = 0;

	vector<int> ans(n, -1), cnts;
	vector<vector<int>> groups;

	for (int i = 0; i < n; i ++) {
		if (ans[i] == -1) {
			ans[i] = 0;
			int cnt = 0;
			vector<int> group;

			auto dfs = [&] (auto &self, int u) -> void {
				group.emplace_back(u);
				cnt += ans[u];
				for (int v = 0; v < n; v ++) {
					if (path[u][v]) {
						if (ans[v] == -1) {
							ans[v] = ans[u] ^ 1;
							self(self, v);
						}
						else if (ans[u] == ans[v]) {
							cout << "impossible";
							exit(0);
						}
					}
				}
			};

			dfs(dfs, i);
			cnts.emplace_back(cnt);
			groups.emplace_back(group);
		}
	}

	int k = cnts.size();
	vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
	dp[0][0] = 1;

	for (int i = 0; i < k; i ++) {
		int c1 = cnts[i], c2 = groups[i].size() - c1;
		for (int j = 0; j <= n; j ++) {
			if (dp[i][j]) {
				dp[i + 1][j + c1] = 1;
				dp[i + 1][j + c2] = 1;
			}
		}
	}

	if (!dp[k][n / 2]) return cout << "impossible", 0;

	int cur = n / 2;
	vector<int> chosen;

	for (int i = k - 1; i >= 0; i --) {
		int c1 = cnts[i], c2 = groups[i].size() - c1;
		if (cur >= c1 && dp[i][cur - c1]) chosen.emplace_back(c1), cur -= c1;
		else chosen.emplace_back(c2), cur -= c2;
	}

	reverse(chosen.begin(), chosen.end());

	for (int i = 0; i < k; i ++) {
		if (chosen[i] != cnts[i]) {
			for (auto &u: groups[i]) {
				ans[u] ^= 1;
			}
		}
	}

	for (auto &x: ans) cout << "rb"[x] << '\n';

	return 0;
}