#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#include "atcoder/dsu.hpp"

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, t;
	cin >> n >> m >> t;
	t --;

	atcoder::dsu uf(n);
	vector<array<int, 3>> edges;

	while (m --) {
		int u, v, x;
		cin >> u >> v >> x;
		u --, v --;
		if (!x) uf.merge(u, v);
		else edges.push_back({u, v, x});
	}

	int inf = 1e9, ans = inf;
	vector<vector<int>> dp(n, vector<int>(n, inf));

	dp[0][uf.leader(0)] = 0;

	for (int i = 0; i < n - 1; i ++) {
		for (auto [u, v, x]: edges) {
			u = uf.leader(u), v = uf.leader(v);
			dp[i + 1][v] = min(dp[i + 1][v], dp[i][u] + i * x);
			dp[i + 1][u] = min(dp[i + 1][u], dp[i][v] + i * x);
		}
	}

	for (auto &v: dp) ans = min(ans, v[uf.leader(t)]);

	cout << (ans < inf ? ans : -1);

	return 0;
}