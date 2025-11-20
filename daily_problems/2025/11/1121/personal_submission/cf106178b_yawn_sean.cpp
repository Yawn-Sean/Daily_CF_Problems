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

	int n, k, mod = 998244353;
	cin >> n >> k;

	n = min(n, k);

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	auto minus = [&] (int &x, int y) -> void {
		x -= y;
		if (x < 0) x += mod;
	};

	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i ++) {
		vector<int> ndp(k + 1, 0);

		for (int j = 0; j <= k; j ++) {
			int start = j * (i - 1) + 1;
			int ending = j * (i - 1) + k;

			int left = (start + i - 1) / i;
			int right = ending / i;

			add(ndp[left], dp[j]);
			if (right < k) minus(ndp[right + 1], dp[j]);
		}

		for (int j = 1; j <= k; j ++)
			add(ndp[j], ndp[j - 1]);
	
		dp.swap(ndp);
	}

	int ans = 0;
	for (auto &x: dp) add(ans, x);
	cout << ans;

	return 0;
}