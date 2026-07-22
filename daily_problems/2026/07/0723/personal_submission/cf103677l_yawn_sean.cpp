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

	int n;
	cin >> n;

	vector<vector<long double>> grid(n, vector<long double>(n));
	for (auto &v: grid) for (auto &x: v) cin >> x;

	vector<long double> dp(1 << n, 0);
	dp.back() = 1;

	for (int i = (1 << n) - 1; i > 0; i --) {
		int c = __popcount(i), total = c * (c - 1) / 2;

		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < j; k ++) {
				if ((i >> j & 1) && (i >> k & 1)) {
					dp[i ^ (1 << j)] += dp[i] * grid[k][j] / total;
					dp[i ^ (1 << k)] += dp[i] * grid[j][k] / total;
				}
			}
		}
	}

	cout << fixed << setprecision(15);
	for (int i = 0; i < n; i ++) cout << dp[1 << i] << '\n';

	return 0;
}