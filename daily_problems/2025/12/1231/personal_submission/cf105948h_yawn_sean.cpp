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

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	int mod = 998244353;
	
	vector<int> f(n + 1), g(n + 1);

	f[0] = 1;
	for (int i = 1; i <= n; i ++) f[i] = 1ll * f[i - 1] * i % mod;
	g[n] = quickPow(f[n], mod - 2, mod);
	for (int i = n; i >= 1; i --) g[i - 1] = 1ll * g[i] * i % mod;

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	auto minus = [&] (int &x, int y) -> void {
		x -= y;
		if (x < 0) x += mod;
	};

	auto comb_inv = [&] (int x, int y) -> int {
		return 1ll * g[x] * f[y] % mod * f[x - y] % mod;
	};

	auto inv = [&] (int x) -> int {
		return 1ll * f[x - 1] * g[x] % mod;
	};

	vector<vector<int>> dp(n + 1, vector<int>(n * n + 1, 0));
	dp[0][0] = 1;

	for (int i = 0; i < n; i ++) {
		for (int j = i; j >= 0; j --) {
			for (int k = 0; k <= n * n; k ++) {
				if (dp[j][k]) {
					add(dp[j + 1][k + nums[i]], dp[j][k]);
				}
			}
		}
	}

	vector<int> ans(n + 1);

	for (auto &v: nums) {
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k <= n * n; k ++) {
				if (dp[j][k]) {
					minus(dp[j + 1][k + v], dp[j][k]);
				}
			}
		}

		for (int j = 1; j < n; j ++) {
			for (int k = 0; k <= n * n; k ++) {
				if (j * v > k) {
					add(ans[j + 1], dp[j][k]);
				}
			}
		}

		for (int j = n - 1; j >= 0; j --) {
			for (int k = 0; k <= n * n; k ++) {
				if (dp[j][k]) {
					add(dp[j + 1][k + v], dp[j][k]);
				}
			}
		}
	}

	for (int i = 2; i <= n; i ++)
		cout << 1ll * ans[i] * comb_inv(n, i) % mod * inv(i) % mod << ' ';

	return 0;
}