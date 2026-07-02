#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

long long quickPow(long long base, long long power, long long mod) {
	base %= mod;
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		long long n, m;
		cin >> n >> m;
		m ++;

		vector<long long> dp(60, 0);
		int c = 0;

		for (int i = 59; i >= 0; i --) {
			for (int j = 58; j >= 0; j --) dp[j + 1] += dp[j];
			if (m >> i & 1) dp[c] ++, c ++;
		}

		int ans = 0;
		for (int i = 0; i < 60; i ++)
			ans = (ans + dp[i] % mod * quickPow(n, i, mod) % mod) % mod;
		cout << ans << '\n';
	}

	return 0;
}