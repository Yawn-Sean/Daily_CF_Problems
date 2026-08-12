#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

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
	for (auto &x: nums) cin >> x;

	if (*max_element(nums.begin(), nums.end()) != 2) cout << "NO\n";
	else if (*min_element(nums.begin(), nums.end()) != 0) cout << "NO\n";
	else {
		for (int i = 0; i < n; i ++) {
			if (nums[i] == nums[(i + 1) % n] && nums[i] != 1) {
				return cout << "NO\n", 0;
			}
		}
		cout << "YES\n";
	}

	return 0;
}