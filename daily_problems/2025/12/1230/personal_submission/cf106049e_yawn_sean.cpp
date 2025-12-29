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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, q;
		cin >> n >> q;

		vector<vector<int>> grid(n, vector<int>(n));
		for (auto &x: grid) for (auto &y: x) cin >> y;

		vector<int> saved(2 * n - 1, 0);
		vector<vector<long long>> dp(n, vector<long long>(n));

		while (q --) {
			int k, v;
			cin >> k >> v;
			k -= 2;

			if (saved[k]) {
				dp[n - 1][n - 1] += v - saved[k];
				saved[k] = v;
			}
			else {
				saved[k] = v;
				for (int i = 0; i < n; i ++) {
					for (int j = 0; j < n; j ++) {
						if (saved[i + j])
							grid[i][j] = saved[i + j];
						dp[i][j] = grid[i][j];
					}
				}
				for (int i = 0; i < n; i ++) {
					for (int j = 0; j < n; j ++) {
						long long w = 0;
						if (i) w = max(w, dp[i - 1][j]);
						if (j) w = max(w, dp[i][j - 1]);
						dp[i][j] += w;
					}
				}
			}

			cout << dp[n - 1][n - 1] << '\n';
		}
	}

	return 0;
}