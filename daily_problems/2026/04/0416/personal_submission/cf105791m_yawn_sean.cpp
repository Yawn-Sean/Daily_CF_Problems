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

	int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	if (n == 1) return cout << 0, 0;

	int inf = 1e9;
	vector<vector<int>> dp(n, vector<int>(1 << n, inf));

	dp[0][1] = 0;

	for (int i = 0; i < (1 << n); i ++) {
		for (int j = 0; j < n; j ++) {
			if (dp[j][i] < inf) {
				for (int nj = 0; nj < n; nj ++) {
					if (i >> nj & 1) continue;
					int ni = i | (1 << nj);
					dp[nj][ni] = min(dp[nj][ni], dp[j][i] + grid[j][nj]);
				}
			}
		}
	}

	int ans = inf;
	for (int i = 1; i < n; i ++) ans = min(ans, dp[i][(1 << n) - 1] + grid[i][0]);

	cout << ans;

	return 0;
}