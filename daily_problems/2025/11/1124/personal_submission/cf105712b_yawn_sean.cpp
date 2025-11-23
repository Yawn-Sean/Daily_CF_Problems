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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		int ma = *max_element(nums.begin(), nums.end());

		if (ma < 2) cout << 0 << '\n';
		else if (n == 2) {
			int x = nums[0], y = nums[1];
			int ans = 0;

			while (x > 1 || y > 1) {
				int nx = x / 2, ny = y / 2;
				x &= 1, y &= 1;
				ans += nx + ny;
				x += ny, y += nx;
			}

			cout << ans << '\n';
		}
		else {
			long long total = 0;
			for (auto &x: nums) total += x;
			cout << (total == 3 && ma == 3 ? 1 : total - 1) << '\n';
		}
	}

	return 0;
}