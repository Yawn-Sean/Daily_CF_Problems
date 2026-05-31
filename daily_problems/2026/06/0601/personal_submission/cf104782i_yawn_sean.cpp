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

	int M = 5e6 + 5, mod = 1e9 + 7;

	vector<int> f(M), g(M);

	f[0] = 1;
	for (int i = 1; i < M; i ++) f[i] = 1ll * i * f[i - 1] % mod;
	g[M - 1] = quickPow(f[M - 1], mod - 2, mod);
	for (int i = M - 1; i > 0; i --) g[i - 1] = 1ll * i * g[i] % mod;

	int k, s, t;
	cin >> k >> s >> t;

	int x = k / t, y = k % t, ans = 0;

	auto comb = [&] (int x, int y) -> int {
		if (x == y) return 1;
		if (y < 0 || x < 0 || y > x) return 0;
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	for (int i = 1; i <= s; i ++) {
		if (x * i > s) break;
		if ((s - i * x) % (x + 1) == 0) {
			int j = (s - i * x) / (x + 1);
			ans += 1ll * comb(i - 1, t - y - 1) * comb(j - 1, y - 1) % mod;
			ans %= mod;
		}
	}

	cout << ans;

	return 0;
}