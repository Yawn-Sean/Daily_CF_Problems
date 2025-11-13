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

	int n, k, mod = 1e9 + 7;
	cin >> n >> k;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	sort(nums.begin(), nums.end());
	
	int M = 1e4 + 2;
	vector<vector<int>> dp(k, vector<int>(M, 0));
	dp[0][0] = 1;

	int ans = 0;

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	for (int i = 0; i < n; i ++) {
		for (int j = nums[i] + 1; j < M; j ++) {
			add(ans, dp[k - 1][j]);
		}

		for (int x = k - 2; x >= 0; x --) {
			for (int y = 0; y < M; y ++) {
				add(dp[x + 1][min(y + nums[i], M - 1)], dp[x][y]);
			}
		}
	}

	cout << ans;

	return 0;
}