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

	int M = 1e6, mod = 998244353;

	vector<int> f(M + 1), g(M + 1);
	f[0] = 1;
	for (int i = 1; i <= M; i ++) f[i] = 1ll * i * f[i - 1] % mod;
	g[M] = quickPow(f[M], mod - 2, mod);
	for (int i = M; i >= 1; i --) g[i - 1] = 1ll * i * g[i] % mod;

	auto comb = [&] (int x, int y) -> int {
		if (y < 0 || y > x) return 0;
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	int n, m;
	cin >> n >> m;

	int ans = 0, target = n * (m + 1) / 2;

	for (int i = 0; i <= target / (m + 1); i ++) {
		int total = target - i * m;
		int v = 1ll * comb(total - 1, n - 1) * comb(n, i) % mod;
		if (i & 1) ans += mod - v;
		else ans += v;
		ans %= mod;
	}

	cout << ans;

	return 0;
}