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

	int n;
	long long s;
	cin >> n >> s;

	vector<long long> nums(n);
	for (auto &v: nums) cin >> v;

	long long cur = 0;
	for (auto &v: nums) cur += v;

	sort(nums.begin(), nums.end());

	vector<long long> acc(n + 1, 0);
	for (int i = 0; i < n; i ++)
		acc[i + 1] = acc[i] + nums[i];

	long long l = 0, r = 2e9;
	while (l <= r) {
		long long mid = (l + r) / 2;
		int pos = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
		if (cur + (mid + 1) * mid / 2 - acc[pos] >= s) r = mid - 1;
		else l = mid + 1;
	}

	int pos = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
	cout << l - pos + n;

	return 0;
}