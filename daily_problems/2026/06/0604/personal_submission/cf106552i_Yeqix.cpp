#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	vector<vector<int>> edge(n + 1);
	vector<vector<int>> f(m + 1, vector<int>(m + 1, inf));
	for (int i = 1; i <= n; i++) {
		int M;
		cin >> M;
		edge[i].reserve(M);
		for (int j = 1; j <= M; j++) {
			int x;
			cin >> x;
			edge[i].push_back(x);
		}
		for (const auto& v : edge[i]) {
			for (const auto& v2 : edge[i]) {
				f[v][v2] = 1 - (v == v2);
			}
		}
	}

	auto dp = f;
	for (int k = 1; k <= m; k++) {
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		int ans = inf;
		for (const auto& v1 : edge[l]) {
			for (const auto& v2 : edge[r]) {
				ans = min(ans, dp[v1][v2]);
			}
		}

		if (ans >= inf) {
			cout << "-1\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}