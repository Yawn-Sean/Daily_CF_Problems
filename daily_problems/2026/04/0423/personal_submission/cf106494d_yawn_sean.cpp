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

	int n;
	cin >> n;

	vector<int> nums(n);
	long long total = 0;
	for (auto &x: nums) cin >> x, total += x * 2;

	sort(nums.begin(), nums.end());

	long long ans = total;

	for (int i = 0; i < n; i ++) {
		total -= nums[i] * 2;
		ans = max(ans, total + nums[i / 2] + nums[i - i / 2]);
	}

	cout << ans;

	return 0;
}