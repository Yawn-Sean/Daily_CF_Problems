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

	int n, M = 2e5;
	cin >> n;

	vector<int> cnt1(M + 1, 0), cnt2(M + 1, 0);
	vector<pair<int, int>> pts(n);

	for (auto &[x, y]: pts) {
		cin >> x >> y;
		cnt1[x] ++, cnt2[y] ++;
	}

	long long ans = 0;

	vector<long long> dp(4, 0);
	dp[0] = 1;

	for (auto &x: cnt1) {
		for (int i = 3; i > 0; i --) {
			dp[i] += dp[i - 1] * x;
		}
	}

	ans += dp[3];

	fill(dp.begin(), dp.end(), 0);
	dp[0] = 1;

	for (auto &x: cnt2) {
		for (int i = 3; i > 0; i --) {
			dp[i] += dp[i - 1] * x;
		}
	}

	ans += dp[3];

	long long dup = 1ll * n * (n - 1) * (n - 2) / 6;

	for (auto &v: cnt1) dup -= 1ll * v * (v - 1) / 2 * (n - v);
	for (auto &v: cnt2) dup -= 1ll * v * (v - 1) / 2 * (n - v);
	for (auto &[x, y]: pts)
		dup += 1ll * (cnt1[x] - 1) * (cnt2[y] - 1);

	for (auto &v: cnt1) dup -= 1ll * v * (v - 1) * (v - 2) / 6;
	for (auto &v: cnt2) dup -= 1ll * v * (v - 1) * (v - 2) / 6;

	cout << ans - dup;

	return 0;
}