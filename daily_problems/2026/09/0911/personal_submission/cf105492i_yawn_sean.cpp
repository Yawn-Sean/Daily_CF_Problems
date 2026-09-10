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

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> days(n);
	for (auto &[t, f]: days) cin >> t >> f;

	vector<array<int, 3>> tickets(k);
	for (auto &[p, d, c]: tickets) cin >> p >> d >> c;

	vector<int> dp(n + 1, 1e9);
	dp[0] = 0;

	vector<int> pts(k, 0);

	for (int i = 0; i < n; i ++) {
		auto [t, f] = days[i];
		dp[i + 1] = dp[i] + f;

		for (int j = 0; j < k; j ++) {
			auto [p, d, c] = tickets[j];
			while (t - days[pts[j]].first + 1 > p || i - pts[j] + 1 > d) pts[j] ++;
			dp[i + 1] = min(dp[i + 1], dp[pts[j]] + c);
		}
	}

	cout << dp[n];

	return 0;
}