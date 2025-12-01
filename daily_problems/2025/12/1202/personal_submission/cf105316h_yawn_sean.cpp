#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
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

	int M = 1e5 + 5, mod = 998244353;

	vector<int> f(M, 1), g(M);

	for (int i = 1; i < M; i ++)
		f[i] = 1ll * f[i - 1] * i % mod;

	g[M - 1] = quickPow(f[M - 1], mod - 2, mod);

	for (int i = M - 1; i > 0; i --)
		g[i - 1] = 1ll * g[i] * i % mod;

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		int ans = 0;
		for (int k = 1; k <= n; k ++) {
			ans += 1ll * (n + 1) * f[k] % mod * g[k + 1] % mod;
			ans %= mod;
		}
		
		cout << ans << '\n';
	}

	return 0;
}