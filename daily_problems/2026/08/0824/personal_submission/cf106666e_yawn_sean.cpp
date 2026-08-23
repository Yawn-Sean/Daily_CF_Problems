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

	int n, mod = 1e9 + 7;
	cin >> n;

	vector<int> dp(n + 1, 0);
	dp[0] = 2;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j <<= 1) {
			dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}

	cout << dp[n];

	return 0;
}