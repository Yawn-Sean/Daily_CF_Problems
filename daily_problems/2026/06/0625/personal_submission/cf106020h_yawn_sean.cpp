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

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	vector<int> idxs;
	for (int i = 0; i < n; i ++) if (nums[i]) idxs.emplace_back(i);

	long long ans = 0;
	for (int i = 1; i < idxs.size(); i ++) {
		int x = idxs[i - 1], y = idxs[i];
		if (min(nums[x], nums[y]) == 1 && max(nums[x], nums[y]) <= 2) {
			int lx = (i >= 2 ? idxs[i - 2] : -1);
			int ry = (i + 1 < idxs.size() ? idxs[i + 1] : n);

			ans += 1ll * (x - lx) * (ry - y);
			if (y - x == 1) ans --;
		}
	}

	cout << ans;

	return 0;
}