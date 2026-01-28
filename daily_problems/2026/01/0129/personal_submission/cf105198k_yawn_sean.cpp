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

	int M = 2e6, mod = 1e9 + 7;

	vector<int> f(M + 1), g(M + 1);
	f[0] = 1;
	for (int i = 1; i <= M; i ++)
		f[i] = 1ll * i * f[i - 1] % mod;
	g[M] = quickPow(f[M], mod - 2, mod);
	for (int i = M; i >= 1; i --)
		g[i - 1] = 1ll * i * g[i] % mod;

	auto comb = [&] (int x, int y) -> int {
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	int t;
	cin >> t;

	while (t --) {
		int b0, g0, x, y;
		cin >> b0 >> g0 >> x >> y;

		if (x + y > g0) cout << "0\n";
		else {
			int ans = 0;
			ans = (ans + comb(b0 + g0, b0)) % mod;
			ans = (ans + mod - comb(b0 + x + y - 1, b0)) % mod;
			cout << ans << '\n';
		}
	}

	return 0;
}