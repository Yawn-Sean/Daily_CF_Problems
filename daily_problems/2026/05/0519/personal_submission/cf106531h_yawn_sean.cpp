#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> path(n);
	vector<int> indeg(n, 0);

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		indeg[v] ++;
	}

	int k;
	cin >> k;

	vector<vector<int>> invalids(n);

	while (k --) {
		int j, x;
		cin >> j >> x;
		invalids[x - 1].emplace_back(j);
	}

	vector<int> dp(n, 1), stk, vis(n, 0);

	for (int i = 0; i < n; i ++) {
		if (!indeg[i]) {
			stk.emplace_back(i);
		}
	}

	while (!stk.empty()) {
		int u = stk.back(); stk.pop_back();
		vis[u] = 1;

		sort(invalids[u].begin(), invalids[u].end());

		for (auto &x: invalids[u]) {
			if (dp[u] == x) {
				dp[u] ++;
			}
		}

		for (auto &v: path[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			indeg[v] --;
			if (!indeg[v]) stk.emplace_back(v);
		}
	}

	if (*min_element(vis.begin(), vis.end())) cout << *max_element(dp.begin(), dp.end());
	else cout << -1;

	return 0;
}