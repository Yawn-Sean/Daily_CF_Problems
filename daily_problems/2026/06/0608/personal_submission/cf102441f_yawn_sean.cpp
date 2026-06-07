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

int cnt[30][30][2][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, x, y;
	cin >> n >> x >> y;

	for (int i = 0; i < n; i ++) {
		int v;
		cin >> v;

		for (int j = 0; j < 30; j ++) {
			for (int k = 0; k < 30; k ++) {
				cnt[j][k][v >> j & 1][v >> k & 1] ++;
			}
		}
	}

	int mod = 1e9 + 7;

	int p1 = x * quickPow(y, mod - 2, mod), p0 = (mod + 1 - p1) % mod;

	vector<int> probs(n + 1, 0);
	int v1 = 0, v0 = 1;

	for (int i = 1; i <= n; i ++) {
		int nv1 = (1ll * v1 * p0 + 1ll * v0 * p1) % mod;
		int nv0 = (1ll * v0 * p0 + 1ll * v1 * p1) % mod;

		v1 = nv1;
		v0 = nv0;

		probs[i] = v1;
	}

	int ans = 0;

	for (int i = 0; i < 30; i ++) {
		for (int j = 0; j < 30; j ++) {
			vector<int> dp(4, 0);
			dp[0] = 1;

			for (int vi = 0; vi < 2; vi ++) {
				for (int vj = 0; vj < 2; vj ++) {
					int v = vi * 2 + vj;
					int x = cnt[i][j][vi][vj];

					int p1 = probs[x];
					int p0 = (mod + 1 - p1) % mod;

					vector<int> ndp(4, 0);

					for (int idx = 0; idx < 4; idx ++) {
						ndp[idx] = (1ll * dp[idx ^ v] * p1 + 1ll * dp[idx] * p0) % mod;
					}

					dp.swap(ndp);
				}
			}
			ans += (1ll << i + j) % mod * dp[3] % mod;
			ans %= mod;
		}
	}

	cout << ans;

	return 0;
}