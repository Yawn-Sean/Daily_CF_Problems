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
	cin >> n;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	vector<int> pref = nums, suff = nums;

	for (int i = 1; i < n; i ++) pref[i] = max(pref[i], pref[i - 1]);
	for (int i = n - 2; i >= 0; i --) suff[i] = max(suff[i], suff[i + 1]);

	long long ans = 0, cur = 0;

	for (int i = 0; i < n; i ++) {
		int x = min(pref[i], suff[i]) - nums[i];
		cur = x ? cur + x : 0;
		ans = max(ans, cur);
	}

	cout << ans;

	return 0;
}