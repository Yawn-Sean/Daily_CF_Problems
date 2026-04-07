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

	int n, q;
	cin >> n >> q;

	vector<vector<int>> cnt(n, vector<int>(n, 0)), dp(n, vector<int>(n, 0));

	while (q --) {
		int l, r;
		cin >> l >> r;
		l --, r --;
		cnt[l][r] ++;
	}

	for (int l = 0; l < n; l ++) {
		for (int r = n - 1; r > 0; r --) {
			cnt[l][r - 1] += cnt[l][r];
		}
	}

	for (int l = 1; l < n; l ++) {
		for (int r = 0; r < n; r ++) {
			cnt[l][r] += cnt[l - 1][r];
		}
	}

	for (int i = 0; i < n; i ++) dp[i][i] = cnt[i][i];

	for (int l = n - 1; l >= 0; l --) {
		for (int r = l + 1; r < n; r ++) {
			dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]) + cnt[l][r];
		}
	}

	cout << dp[0][n - 1];

	return 0;
}