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

	int t, inf = 1e9;
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		vector<vector<int>> dp(n, vector<int>(n, inf));
		for (int i = 1; i < n; i ++) dp[i][i - 1] = 0;

		for (int diff = 1; diff < n; diff ++) {
			for (int l = 0; l + diff < n; l ++) {
				int r = l + diff;
				for (int i = l; i < r; i ++)
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r]);
				int ma = max(nums[l], nums[r]);
				int mi = min(nums[l], nums[r]);
				for (int i = l + 1; i < r; i ++) {
					if (max(ma, nums[i]) - min(mi, nums[i]) <= k) {
						dp[l][r] = min(dp[l][r], dp[l + 1][i - 1] + dp[i + 1][r - 1] + 1);
					}
				}
				if (ma - mi <= k) dp[l][r] = min(dp[l][r], dp[l + 1][r - 1] + 1);
			}
		}

		vector<pair<int, int>> dp1(n + 1, {inf, inf});
		dp1[0] = {0, 0};

		for (int i = 0; i < n; i ++) {
			dp1[i + 1] = min(dp1[i + 1], {dp1[i].first + 1, dp1[i].second});
			for (int j = i; j < n; j ++) {
				if (dp[i][j] < inf) {
					dp1[j + 1] = min(dp1[j + 1], {dp1[i].first, dp1[i].second + dp[i][j]});
				}
			}
		}

		cout << dp1[n].first << ' ' << dp1[n].second << '\n';
	}

	return 0;
}