#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, mod = 1e9 + 7;
	cin >> n;

	if (n < 3) cout << n;
	else {
		vector<int> dp(n + 1, 1);

		for (int i = 3; i < n; i ++) {
			dp[n] = (dp[n] + dp[i]) % mod;
			for (int j = 2 * i - 1; j < n; j += i)
				dp[j] = (dp[j] + dp[i]) % mod;
			for (int j = 2 * i; j < n; j += i)
				dp[j] = (dp[j] + dp[i]) % mod;
			for (int j = i + 1; j < n; j += i)
				dp[j] = (dp[j] + dp[i]) % mod;
		}

		cout << 2ll * n * dp[n] % mod;
	}

	return 0;
}