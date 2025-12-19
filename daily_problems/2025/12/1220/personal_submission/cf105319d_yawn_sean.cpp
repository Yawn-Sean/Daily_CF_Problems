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

	int l = 0, r = 0;
	long long ans = 0;

	vector<int> c0(30, 0), c1(30, 0);

	while (l < n) {
		while (r + 1 < n) {
			if (nums[r] ^ nums[r + 1]) {
				int v = 31 - __builtin_clz(nums[r] ^ nums[r + 1]);
				if (v >= 0) {
					if (nums[r] >> v & 1) {
						if (c0[v]) break;
						c1[v] ++;
					}
					else {
						if (c1[v]) break;
						c0[v] ++;
					}
				}
			}
			r ++;
		}

		ans += r - l + 1;
		if (l + 1 < n && nums[l] != nums[l + 1]) {
			int v = 31 - __builtin_clz(nums[l] ^ nums[l + 1]);
			if (v >= 0) {
				if (nums[l] >> v & 1) c1[v] --;
				else c0[v] --;
			}
		}
		l ++;
	}

	cout << ans;

	return 0;
}