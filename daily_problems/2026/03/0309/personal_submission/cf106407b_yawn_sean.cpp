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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		if ((n * (n + 1) / 2) & 1) cout << "0\n";
		else {
			int M = n * (n + 1) / 4;
			vector<vector<int>> dp(n / 2 + 2, vector<int>(M + 1, 0));
			dp[0][0] = 1;

			for (int x = 0; x <= n; x ++) {
				for (int i = n / 2 + 1; i >= 1; i --) {
					for (int j = x; j <= M; j ++) {
						dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
					}
				}
			}

			n ++;
			int ans = 1ll * (dp[n / 2][M] + dp[n - n / 2][M]) * (mod + 1) / 2 % mod;

			for (int x = 1; x <= n / 2; x ++) ans = 1ll * ans * x % mod;
			for (int x = 1; x <= n - n / 2; x ++) ans = 1ll * ans * x % mod;

			cout << ans << '\n';
		}
	}

	return 0;
}