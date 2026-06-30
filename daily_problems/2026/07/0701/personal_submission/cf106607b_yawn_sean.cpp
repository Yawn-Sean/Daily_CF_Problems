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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		
		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		int l = n, r = -1;
		for (int i = 0; i < n; i ++) {
			if (nums[i] != 1) {
				l = min(l, i);
				r = max(r, i);
			}
		}

		if (l > r) cout << 0 << '\n';
		else {
			bool flg = true;
			for (int i = l; i <= r; i ++) {
				if (nums[i] != nums[l]) {
					flg = false;
				}
			}
			cout << (flg ? 1 : 2) << '\n';
		}
	}

	return 0;
}