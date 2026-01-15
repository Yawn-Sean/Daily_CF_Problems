#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	int n, q;
	cin >> n >> q;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;
	sort(nums.begin(), nums.end());

	while (q --) {
		int t;
		cin >> t;

		if (t == 1) {
			int v;
			cin >> v;

			if (v > nums.back()) nums.emplace_back(v);
			else {
				int pos = upper_bound(nums.begin(), nums.end(), v) - nums.begin();
				if (pos && nums[pos - 1] == v) continue;
				else nums[pos] = v;
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << upper_bound(nums.begin(), nums.end(), r) - lower_bound(nums.begin(), nums.end(), l) << '\n';
		}
	}

	return 0;
}