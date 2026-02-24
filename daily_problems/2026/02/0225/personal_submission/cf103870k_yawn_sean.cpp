#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, mod;
	cin >> n >> mod;

	vector<int> f(n + 1), g(n + 1);
	f[0] = 1;
	for (int i = 1; i <= n; i ++)
		f[i] = 1ll * i * f[i - 1] % mod;
	g[n] = quickPow(f[n], mod - 2, mod);
	for (int i = n; i >= 1; i --)
		g[i - 1] = 1ll * i * g[i] % mod;

	int p1 = quickPow(3, mod - 2, mod), p2 = 2ll * p1 % mod;
	int v = 2, v1 = p1, v2 = p2;

	auto comb = [&] (int i, int j) -> int {
		return 1ll * f[i] * g[j] % mod * g[i - j] % mod;
	};

	vector<int> dp(n + 1, 0);

	for (int i = 2; i <= n; i ++) {
		v = 2ll * v % mod;
		v1 = 1ll * v1 * p1 % mod;
		v2 = 1ll * v2 * p2 % mod;

		for (int j = 0; j < i; j ++)
			dp[i] = (dp[i] + 1ll * comb(i, j) * dp[j]) % mod;

		dp[i] = 1ll * dp[i] * quickPow(v - 2, mod - 2, mod) % mod;
		int val = 3ll * v2 % mod - 6ll * v1 % mod;
		val = (val + mod) % mod;
		dp[i] = (dp[i] + quickPow(val, mod - 2, mod)) % mod;
	}

	for (int i = 1; i <= n; i ++) cout << dp[i] << ' ';

	return 0;
}