#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
static constexpr i64 mod = 1e9 + 7;
void solve() {
	std::string s, t;
	std::cin >> s >> t;
	i64 ans = 0;
	int n = s.size();
	int m = t.size();
	std::vector dp(n + 1, std::vector<i64>(m + 1));
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] += dp[i][j];
				dp[i + 1][j + 1] %= mod;
				ans += dp[i][j];
				ans %= mod;
			}
			dp[i][j + 1] += dp[i][j];
			dp[i][j + 1] %= mod;
		}

	}
	std::cout << ans << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
