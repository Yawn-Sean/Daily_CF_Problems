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

	int n, mod = 1e9 + 7;
	cin >> n;

	vector<int> dp(n + 1, 0), acc(n + 1, 0);
	dp[1] = 1, acc[1] = 1;

	for (int i = 2; i <= n; i ++) {
		dp[i] = (acc[i - 1] + mod - acc[i - i / 2 - 1]) % mod;
		acc[i] = (acc[i - 1] + dp[i]) % mod;
	}

	cout << dp[n];

	return 0;
}