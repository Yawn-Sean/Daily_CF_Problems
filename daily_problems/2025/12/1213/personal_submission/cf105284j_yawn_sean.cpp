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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	if (n < m) {
		vector<vector<int>> ngrid(m, vector<int>(n));
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ngrid[j][i] = grid[i][j];
			}
		}
		swap(n, m);
		swap(grid, ngrid);
	}

	int mod = 998244353;
	vector<int> dp(1 << m, 0);
	dp[0] = 1;

	int rev2 = quickPow(2, mod - 2, mod), rev6 = quickPow(6, mod - 2, mod);

	for (int i = 0; i < n; i ++) {
		vector<int> ndp(1 << m, 0);

		for (int j = 0; j < m; j ++) {
			int v = grid[i][j];
			int v0 = (v + 1) % mod;
			int v1 = 1ll * v * (v + 1) % mod * rev2 % mod;
			int v2 = 1ll * v * (v + 1) % mod * (2 * v + 1) % mod * rev6 % mod;

			for (int msk = (1 << m) - 1; msk >= 0; msk --) {
				ndp[msk] = (1ll * ndp[msk] * v0 + 1ll * dp[msk] * v1) % mod;
				dp[msk] = 1ll * dp[msk] * v0 % mod;

				if (msk >> j & 1) {
					int nmsk = msk ^ (1 << j);
					ndp[msk] = (ndp[msk] + 1ll * dp[nmsk] * v2 + 1ll * ndp[nmsk] * v1) % mod;
					dp[msk] = (dp[msk] + 1ll * dp[nmsk] * v1) % mod;
				}
			}
		}

		dp.swap(ndp);
	}

	cout << dp.back();

	return 0;
}