#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> path(n);
	vector<i64> deg(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		if (u > v) {
			swap(u, v);
		}
		path[u].push_back(v);
		deg[u]++;
		deg[v]++;
	}
	
	vector<i64> dp(n, 1);
	for (int x = 0; x < n; x++) {
		for (auto& y: path[x]) {
			dp[y] = max(dp[y], dp[x] + 1);
		}
	}
	
	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i] * deg[i]);
	}
	cout << ans << '\n';
	return 0;
}
