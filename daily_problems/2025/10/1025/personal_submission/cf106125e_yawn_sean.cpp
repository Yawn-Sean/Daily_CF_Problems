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

	vector<int> nums(n, 0);

	while (true) {
		int cur_mi = 0, mi_idx = -1, cur = 0, max_seg = 0, l = -1, r = 0;
		for (int i = 0; i < n; i ++) {
			cur += (nums[i] ? -1 : 1);
			if (cur < cur_mi) {
				cur_mi = cur;
				mi_idx = i;
			}
			if (cur - cur_mi > max_seg) {
				max_seg = cur - cur_mi;
				l = mi_idx, r = i;
			}
		}

		cout << l + 2 << ' ' << r + 1 << endl;
		for (auto &x: nums) cin >> x;

		int val;
		cin >> val;
		
		if (val >= 70) break;
	}

	return 0;
}