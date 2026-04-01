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

	int n, k, mod = 1e9 + 7;
	cin >> n >> k;

	vector<vector<int>> dp(k + 1, vector<int>(1 << n, 0));
	dp[0][0] = 1;

	for (int i = 0; i <= k; i ++) {
		for (int j = 0; j < (1 << n); j ++) {
			int cnt = __popcount(j);
			int smaller = 0;
			for (int bit = 0; bit < n; bit ++) {
				if (j >> bit & 1) continue;
				int ni = i + smaller - max(bit - cnt, 0);
				int nj = j | (1 << bit);
				if (ni <= k)
					dp[ni][nj] = (dp[i][j] + dp[ni][nj]) % mod;
				smaller ++;
			}
		}
	}

	cout << dp[k].back();

	return 0;
}