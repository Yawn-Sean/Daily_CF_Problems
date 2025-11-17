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

	int n, mod = 998244353;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	sort(nums.begin(), nums.end());
	vector<vector<int>> dp(n, vector<int>(n, 0)), dp_acc(n, vector<int>(n, 0));

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	for (int i = 0; i < n; i ++) {
		int pos = 0;
		for (int j = i + 1; j < n; j ++) {
			while (pos < i && nums[pos] + nums[i] <= nums[j]) pos ++;
			if (pos) dp[i][j] = dp_acc[pos - 1][i];
			add(dp[i][j], 1);
			if (i) dp_acc[i][j] = dp_acc[i - 1][j];
			add(dp_acc[i][j], dp[i][j]);
		}
	}

	int ans = n;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			add(ans, dp[i][j]);
		}
	}

	cout << ans;

	return 0;
}