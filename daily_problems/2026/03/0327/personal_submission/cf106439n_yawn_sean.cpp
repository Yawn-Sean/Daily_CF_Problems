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

	int M = 2e5 + 5, mod = 1e9 + 7;

	vector<int> pw2(M, 1), dp(M, 0);
	for (int i = 1; i < M; i ++) pw2[i] = 2 * pw2[i - 1] % mod;
	
	dp[1] = 1;
	for (int i = 2; i < M; i ++)
		dp[i] = (dp[i - 1] + 2ll * dp[i - 2] + pw2[i - 1]) % mod;

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}