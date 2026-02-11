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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		int ans = -1;
		for (int i = 1; i < n; i ++) {
			if (nums[i] <= nums[i - 1]) {
				ans = nums[i - 1] / (nums[i] - 1);
			}
		}

		if (ans == -1) ans = max(nums[n - 1] - nums[n - 2], nums[n - 1] / (nums[n - 1] - nums[n - 2]));
		cout << ans << '\n';
	}

	return 0;
}