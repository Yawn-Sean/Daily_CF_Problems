#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
using i128 = __int128;
static constexpr i64 mod = 1e9 + 7;
i64 f[100005], inv[100005];
i64 qpow(i64 a, i64 b) {
	i64 ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b = b >> 1;
	}
	return ans;
}
void init() {
	f[0] = 1;
	for (int i = 1; i <= 1e5; i++) {
		f[i] = f[i - 1] * i % mod;
	}
	inv[100000] = qpow(f[100000], mod - 2);
	for (int i = 1e5; i > 0; i--) {
		inv[i - 1] = inv[i] * i % mod;
	}
}
i64 c(int a, int b) {
	if (b > a || b < 0) {
		return 0;
	}
	return f[a] * inv[b] % mod * inv[a - b] % mod;
}
void solve() {
	int n, m;
	std::cin >> n >> m;
	if (n == 1 && m == 1) {
		std::cout << 1 << endl;
	}
	else if (n * 2 > m) {
		std::cout << 0 << endl;
	}
	else {
		i64 ans = 1;
		ans = ans * f[n] % mod;
		// i64 res = c(m - 3, n - 1);
		// // std::cerr << res << endl;
		// if (n - 2 != 0)
		// 	res = res - c(m - 4, n - 2) + mod;
		// // std::cerr << res << endl;
		i64 res = c(m - n, n) * m % mod * qpow(m - n, mod - 2) % mod;
		res %= mod;
		ans = ans * res % mod;
		std::cout << ans << endl;
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	init();
	while (t--) {
		solve();
	}
	return 0;
}
