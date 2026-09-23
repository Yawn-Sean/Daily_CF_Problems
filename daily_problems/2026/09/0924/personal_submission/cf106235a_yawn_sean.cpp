#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, mod = 998244353;
	cin >> n >> k;

	vector<int> p(n), s(n);
	for (auto &x: p) cin >> x;
	for (auto &x: s) cin >> x;

	vector<int> f(n + 1), g(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i ++) f[i] = 1ll * f[i - 1] * i % mod;
	g[n] = quickPow(f[n], mod - 2, mod);
	for (int i = n; i >= 1; i --) g[i - 1] = 1ll * g[i] * i % mod;

	auto comb = [&] (int x, int y) -> int {
		if (y < 0 || y > x) return 0;
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	int ans = comb(n, k);

	for (int i = 0; i < n; i ++) {
		int c = 0;
		for (int j = 0; j < n; j ++) {
			if (p[j] < p[i] && s[j] < s[i]) {
				c ++;
			}
		}
		ans += mod - comb(c, k - 1);
		ans %= mod;
	}

	cout << ans;

	return 0;
}