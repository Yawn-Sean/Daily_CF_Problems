#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, z;
	cin >> n >> z;

	vector<array<int, 3>> activities(n);
	for (auto &[k, d, x]: activities) cin >> k >> d >> x;

	activities.push_back({0, 1, 0});

	vector<vector<long long>> dp(z + 1, vector<long long>(n + 1, 0));
	
	for (int i = 0; i < z; i ++) {
		long long ma1 = 0, ma2 = 0;

		for (int j = 0; j <= n; j ++) {
			auto [k, d, x] = activities[j];
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + k - x);

			if (dp[i][j] > ma1) swap(ma1, ma2), ma1 = dp[i][j];
			else if (dp[i][j] > ma2) ma2 = dp[i][j];
		}

		for (int j = 0; j <= n; j ++) {
			auto [k, d, x] = activities[j];
			int nd = min(z - i, d);

			for (int v = 1; v <= nd; v ++)
				dp[i + v][j] = max(dp[i + v][j], (dp[i][j] == ma1 ? ma2 : ma1) + 1ll * v * k);
		}
	}

	cout << *max_element(dp[z].begin(), dp[z].end());

	return 0;
}