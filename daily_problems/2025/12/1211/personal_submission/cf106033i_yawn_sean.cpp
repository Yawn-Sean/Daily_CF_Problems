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

	int n, k, mod = 998244353;
	cin >> n >> k, n --;

	vector<int> f(2 * n + 1), g(2 * n + 1);
	f[0] = 1;

	for (int i = 1; i <= 2 * n; i ++) f[i] = 1ll * i * f[i - 1] % mod;
	g[2 * n] = quickPow(f[2 * n], mod - 2, mod);
	for (int i = 2 * n; i >= 1; i --) g[i - 1] = 1ll * i * g[i] % mod;

	auto comb = [&] (int x, int y) -> int {
		if (y < 0 || y > x) return 0;
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	int ans = 0;

	for (int i = n - k - 1; i <= n + k; i ++)
		ans = (ans + comb(2 * n, i)) % mod;

	cout << ans;

	return 0;
}