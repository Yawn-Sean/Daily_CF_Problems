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
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		long long total = 0;
		for (auto &v: nums) total += v;

		long long ans = 0;
		ans ^= total;
		ans ^= total - nums[0];
		ans ^= total - nums[n - 1];
		if (n > 1) ans ^= total - nums[0] - nums[n - 1];

		cout << ans << '\n';
	}

	return 0;
}