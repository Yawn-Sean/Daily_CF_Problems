#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, mod = 998244353;
	long long d;
	cin >> n >> d;

	vector<int> f(n + 1), g(n + 1);

	f[0] = 1;
	for (int i = 1; i <= n; i ++) f[i] = 1ll * i * f[i - 1] % mod;

	g[n] = quickPow(f[n], mod - 2, mod);
	for (int i = n; i >= 1; i --) g[i - 1] = 1ll * i * g[i] % mod;

	vector<int> pw2(n + 1);
	pw2[0] = 1;

	for (int i = 1; i <= n; i ++) pw2[i] = 2ll * pw2[i - 1] % mod;

	auto comb = [&] (int x, long long y) -> int {
		if (y > x || y < 0) return 0;
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	int ans = 0;

	for (int i = 0; i <= n / 2; i ++) {
		int val = 1ll * f[n - i] * comb(n / 2, i) % mod * pw2[i] % mod;
		if (i & 1) ans += mod - val;
		else ans += val;
		ans %= mod;
	}

	ans = ans * quickPow(pw2[n / 2], mod - 2, mod) % mod;

	if ((n / 2 - d) & 1) cout << 0;
	else cout << 1ll * ans * comb(n / 2, (n / 2 + d) / 2) % mod;

	return 0;
}