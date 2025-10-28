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

	vector<int> nums(n), parent(n, -1);

	for (auto &x: nums) cin >> x;
	for (int i = 1; i < n; i ++) cin >> parent[i], parent[i] --;

	int ans = 0;
	vector<int> dp1(n, 0), dp2(n, 0);

	for (int i = n - 1; i >= 0; i --) {
		ans = max(ans, dp1[i] + dp2[i]);
		ans = max(ans, nums[i] + dp1[i]);

		if (i) {
			int v = max(nums[i], dp1[i]) + 1, p = parent[i];
			if (v > dp1[p]) swap(dp1[p], dp2[p]), dp1[p] = v;
			else if (v > dp2[p]) dp2[p] = v;
		}
	}

	cout << ans;

	return 0;
}