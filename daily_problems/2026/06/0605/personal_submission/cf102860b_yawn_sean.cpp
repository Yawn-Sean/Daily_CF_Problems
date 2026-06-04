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

	int n, l;
	cin >> n >> l;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i ++) nums.emplace_back(nums[i] + l);

	int r = 0;
	long long ans = 1ll * n * (n - 1) * (n - 2) / 6;

	for (int i = 0; i < n; i ++) {
		while (2 * (nums[r] - nums[i]) < l) r ++;
		int v = r - i - 1;
		ans -= 1ll * v * (v - 1) / 2;
	}

	cout << ans;

	return 0;
}