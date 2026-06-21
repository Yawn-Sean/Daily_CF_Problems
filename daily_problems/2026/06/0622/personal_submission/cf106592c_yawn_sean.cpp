#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		long long k;
		int n;
		cin >> k >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		int l = 0, r = 1e9;

		while (l <= r) {
			int mid = (l + r) / 2;
			long long val = 0;

			for (auto &x: nums) val += min(mid, x);

			if (val > k) r = mid - 1;
			else l = mid + 1;
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i ++) {
			ans[i] = min(nums[i], r);
			k -= ans[i];
		}

		for (int i = 0; i < n; i ++) {
			if (ans[i] < nums[i] && k) {
				ans[i] ++;
				k --;
			}
		}

		for (int i = 0; i < n; i ++) cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}