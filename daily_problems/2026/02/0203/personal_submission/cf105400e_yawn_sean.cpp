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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		int ma = *max_element(nums.begin(), nums.end());
		int mi = *min_element(nums.begin(), nums.end());

		int ans = 1;
		if (ma == mi)
			for (int i = 0; i < n; i ++) ans *= 10;
		else {
			for (auto &x: nums) {
				if (x == mi) ans *= x;
				else if (x == ma) ans *= 11 - x;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}