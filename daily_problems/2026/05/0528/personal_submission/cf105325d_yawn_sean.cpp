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

		vector<int> nums(n), diff(n + 1, 0);
		for (auto &x: nums) {
			cin >> x;
			diff[0] ++;
			diff[min(n, x)] --;
		}

		for (int i = 1; i <= n; i ++) diff[i] += diff[i - 1];

		long long ans = 0;
		for (int i = 0; i < n; i ++) {
			ans += nums[i] - min(nums[i], diff[i]);
		}

		cout << ans << '\n';
	}

	return 0;
}