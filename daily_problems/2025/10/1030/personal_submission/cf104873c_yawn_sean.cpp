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

	int mod = 998244353, M = 1e5, CNT = 450;

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	vector<vector<int>> dp(CNT, vector<int>(M + 1, 0));
	dp[0][0] = 1;

	for (int i = 1; i < 450; i ++) {
		for (int j = 0; j <= M; j ++) {
			add(dp[i][j], dp[i - 1][j]);
			if (j >= i) add(dp[i][j], dp[i][j - i]);
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		int ans = 0;
		for (int i = 1; i < 450; i ++) {
			if ((n + i) % 2 == 0 && i * i <= n) {
				add(ans, dp[i][(n - i * i) / 2]);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}