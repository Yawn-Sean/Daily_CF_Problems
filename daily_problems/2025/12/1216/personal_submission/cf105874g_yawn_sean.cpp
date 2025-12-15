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

const int mod = 998244353;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 2e5;
	vector<int> f(M * 2 + 1), g(M * 2 + 1);

	f[0] = 1;
	for (int i = 1; i <= M * 2; i ++) f[i] = 1ll * f[i - 1] * i % mod;
	g[M * 2] = quickPow(f[M * 2], mod - 2, mod);
	for (int i = M * 2; i >= 1; i --) g[i - 1] = 1ll * g[i] * i % mod;

	auto comb = [&] (int x, int y) -> int {
		if (y < 0 || y > x) return 0;
		return 1ll * f[x] * g[y] % mod * g[x - y] % mod;
	};

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	vector<vector<int>> saved_dp(451, vector<int>(M + 1, 0));

	for (int i = 1; i <= 450; i ++) {
		saved_dp[i][0] = 1;

		for (int j = 1; j <= M; j ++) {
			saved_dp[i][j] = saved_dp[i][j - 1];
			if (j >= i) add(saved_dp[i][j], saved_dp[i][j - i]);
		}

		for (int j = 1; j <= M; j ++)
			add(saved_dp[i][j], saved_dp[i][j - 1]);
	}

	int n, q;
	cin >> n >> q;

	while (q --) {
		int l, r, k;
		cin >> l >> r >> k;

		if (k <= 450)
			cout << (saved_dp[k][r] - saved_dp[k][l - 1] + mod) % mod << '\n';
		else {
			int ans = 0;
			for (int cnt_k = 0; cnt_k <= r / k; cnt_k ++) {
				int lbound = max(l - cnt_k * k, 0) - 1;
				int rbound = r - cnt_k * k;

				add(ans, comb(rbound + cnt_k + 1, cnt_k + 1));
				add(ans, mod - comb(lbound + cnt_k + 1, cnt_k + 1));
			}
			cout << ans << '\n';
		}
	}

	return 0;
}