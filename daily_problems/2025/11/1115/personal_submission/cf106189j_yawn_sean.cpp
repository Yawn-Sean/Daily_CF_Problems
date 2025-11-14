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

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int diff = 1; diff < n; diff ++) {
		for (int l = 0; l + diff < n; l ++) {
			int r = l + diff;

			dp[l][r] = dp[l + 1][r - 1];
			if (nums[l] % nums[r] == 0 || nums[r] % nums[l] == 0)
				dp[l][r] += 2;
			
			for (int sep = l; sep < r; sep ++)
				dp[l][r] = max(dp[l][r], dp[l][sep] + dp[sep + 1][r]);
		}
	}

	vector<int> used(n, 0);

	auto check = [&] (auto &self, int l, int r) -> void {
		if (l >= r) return ;
		
		for (int sep = l; sep < r; sep ++) {
			if (dp[l][r] == dp[l][sep] + dp[sep + 1][r]) {
				self(self, l, sep);
				self(self, sep + 1, r);
				return ;
			}
		}

		if (nums[l] % nums[r] == 0 || nums[r] % nums[l] == 0) {
			used[l] = 1;
			used[r] = 1;
		}
		self(self, l + 1, r - 1);
	};

	check(check, 0, n - 1);

	cout << n - dp[0][n - 1] << '\n';
	for (int i = 0; i < n; i ++)
		if (!used[i]) cout << i + 1 << ' ';

	return 0;
}