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

	int M = 2e6, mod = 998244353;

	vector<int> f(M + 5, 1), g(M + 5);

	for (int i = 1; i < M + 5; i ++)
		f[i] = 1ll * i * f[i - 1] % mod;

	g[M + 4] = quickPow(f[M + 4], mod - 2, mod);

	for (int i = M + 4; i > 0; i --)
		g[i - 1] = 1ll * i * g[i] % mod;

	auto inv = [&] (int x) -> int {
		return 1ll * g[x] * f[x - 1] % mod;
	};

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	vector<int> dp(M, 0);
	dp[0] = 1;

	int v0 = 1, v1 = 0;

	for (int i = 1; i < M; i ++) {
		dp[i] = (1ll * (i + 1) * v0 % mod + mod - v1) % mod * 2 % mod * inv(i) % mod * inv(i + 3) % mod;
		add(dp[i], 1);
		add(v0, dp[i]);
		add(v1, 1ll * dp[i] * i % mod);
	}

	int t, rev2 = (mod + 1) / 2;
	cin >> t;

	while (t --) {
		int l, r;
		cin >> l >> r;
		cout << 1ll * (l + r) * rev2 % mod * dp[r - l] % mod << '\n';
	}

	return 0;
}