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

	int M = 1e6 + 5, mod = 998244353;

	vector<int> mis(M, 0), dp(M, 0);

	mis[0] = 1;
	for (int i = 2; i < M; i ++)
		mis[i] = 1ll * (i - 1) * (mis[i - 1] + mis[i - 2]) % mod;

	for (int i = 3; i < M; i ++)
		dp[i] = (dp[i - 1] + 1ll * (i - 1) * mis[i - 1]) % mod * i % mod;

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}