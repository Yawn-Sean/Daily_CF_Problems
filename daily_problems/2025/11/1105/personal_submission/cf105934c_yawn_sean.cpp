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

	long long ans = 1e16, res;
	int cur;

	res = 0, cur = nums[0];

	for (int i = 1; i < n; i ++) {
		if (i & 1) {
			cur = max(cur + 1, nums[i]);
			res += cur - nums[i];
		}
		else {
			cur = min(cur - 1, nums[i]);
			res += nums[i] - cur;
		}
	}

	ans = min(ans, res);

	res = 0, cur = nums[0];

	for (int i = 1; i < n; i ++) {
		if (i & 1) {
			cur = min(cur - 1, nums[i]);
			res += nums[i] - cur;
		}
		else {
			cur = max(cur + 1, nums[i]);
			res += cur - nums[i];
		}
	}

	ans = min(ans, res);

	cout << ans;

	return 0;
}