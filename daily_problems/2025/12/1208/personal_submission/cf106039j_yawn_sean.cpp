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

	int n, m, s, t;
	cin >> n >> m >> s >> t;

	s --, t --;

	vector<vector<int>> path(n);
	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<int> dis(n, -1);
	vector<vector<int>> saved(n);
	dis[s] = 0;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		saved[dis[u]].emplace_back(u);
		for (auto &v: path[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

	int mod = 1e9 + 7;
	vector<vector<int>> dp(2, vector<int>(n, 0));
	dp[0][s] = 1;

	for (int i = 0; i < n; i ++) {
		for (auto &u: saved[i]) {
			for (auto &v: path[u]) {
				if (dis[v] == dis[u]) {
					dp[1][v] = (dp[1][v] + dp[0][u]) % mod;
				}
			}
		}
		for (auto &u: saved[i]) {
			for (auto &v: path[u]) {
				if (dis[v] == dis[u] + 1) {
					dp[0][v] = (dp[0][v] + dp[0][u]) % mod;
					dp[1][v] = (dp[1][v] + dp[1][u]) % mod;
				}
			}
		}
	}

	cout << dp[1][t];

	return 0;
}