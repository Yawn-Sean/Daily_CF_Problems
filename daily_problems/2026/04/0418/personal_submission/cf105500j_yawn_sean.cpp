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

	int ans = 0;

	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < k; i ++) {
		vector<int> ndp(n + 1, 0);

		for (int j = 0; j <= n; j ++) {
			if (i && i + j <= n) dp[i + j] = (dp[i + j] + dp[j]) % mod;
			if (i + 1 <= n && j + 1 <= n) ndp[j + 1] = (ndp[j + 1] + dp[j]) % mod;
		}

		int y = k - i;
		for (int x = 1; x <= n / y; x ++) ans = (ans + 1ll * x * x * dp[n - y * x]) % mod;

		dp.swap(ndp);
	}

	cout << ans;

	return 0;
}