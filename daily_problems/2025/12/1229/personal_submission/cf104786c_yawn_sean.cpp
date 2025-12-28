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

	int n, x, y, mod = 1e9 + 7;
	cin >> n >> x >> y;

	x = n - x, y = n - y;
	vector<vector<int>> dp(x + 1, vector<int>(x + 1, 0));

	int rev2 = (mod + 1) / 2;

	for (int i = 0; i <= x; i ++) {
		for (int j = 0; j < i; j ++) {
			int v = dp[i - 1][abs(j - 1)];
			if (j + 1 <= i - 1) v += dp[i - 1][j + 1];
			dp[i][j] = (1ll * v * rev2 + 1) % mod;
		}
	}

	cout << dp[x][y];

	return 0;
}