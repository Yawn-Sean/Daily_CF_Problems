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

	int n, m;
	cin >> n >> m;

	int mod = 998244353;
	vector<int> cnt(1 << n, 1);

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		
		for (int i = 0; i < (1 << n); i ++) {
			if ((i >> u & 1) && (i >> v & 1)) {
				add(cnt[i], cnt[i]);
			}
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(1 << n, 0));

	for (int i = 1; i < (1 << n); i ++) {
		int bit = 1 << 31 - __builtin_clz(i);
		int cur = i;

		while (cur & bit) {
			for (int j = 2; j <= n; j ++)
				add(dp[j][i], 1ll * dp[1][cur] * dp[j - 1][i - cur] % mod);
			cur = (cur - 1) & i;
		}

		dp[1][i] = cnt[i];
		for (int j = 2; j <= n; j ++) add(dp[1][i], mod - dp[j][i]);
	}

	for (int i = 1; i <= n; i ++) cout << dp[i].back() << '\n';

	return 0;
}