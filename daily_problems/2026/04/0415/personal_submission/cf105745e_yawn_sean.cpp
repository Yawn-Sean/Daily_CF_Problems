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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y, z, mod = 1e9 + 7, M = 301;
	cin >> x >> y >> z;

	vector<vector<int>> combs(M, vector<int>(M, 0));

	for (int i = 0; i < M; i ++) {
		combs[i][0] = 1;
		combs[i][i] = 1;

		for (int j = 1; j < i; j ++) {
			combs[i][j] = (combs[i - 1][j - 1] + combs[i - 1][j]) % mod;
		}
	}

	auto c = [&] (int x, int y) -> int {
		if (x == y) return 1;
		if (y < 0 || y > x) return 0;
		return combs[x][y];
	};

	vector<vector<int>> dp(3, vector<int>(M * M, 0));

	auto f = [&] (int i, int j) -> int {return i * M + j;};

	dp[1][f(1, 0)] = 1, dp[2][f(0, 1)] = 1;

	vector<int> ans(x + y + z, 0);

	for (int i = 0; i <= x; i ++) {
		vector<vector<int>> ndp(3, vector<int>(M * M, 0));

		for (int j = 0; j <= y; j ++) {
			for (int k = 0; k <= z; k ++) {
				if (i + j + k > 1) {
					if (j) dp[1][f(j, k)] = (dp[0][f(j - 1, k)] + dp[2][f(j - 1, k)]) % mod;
					if (k) dp[2][f(j, k)] = (dp[0][f(j, k - 1)] + dp[1][f(j, k - 1)]) % mod;
				}
				for (int cur = 0; cur < 3; cur ++) {
					if (i || j || k) {
						ans[i + j + k - 1] = (ans[i + j + k - 1] + 1ll * dp[cur][f(j, k)] * c(x - 1, i - 1) % mod * c(y - 1, j - 1) % mod * c(z - 1, k - 1) % mod) % mod;
					}
				}
				ndp[0][f(j, k)] = (dp[1][f(j, k)] + dp[2][f(j, k)]) % mod;
			}
		}
		
		if (!i) ndp[0][f(0, 0)] = 1;

		dp.swap(ndp);
	}

	for (auto &x: ans) cout << x << '\n';

	return 0;
}