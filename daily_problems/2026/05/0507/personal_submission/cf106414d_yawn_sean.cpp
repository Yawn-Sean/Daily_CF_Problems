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
		int n, k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		swap(nums[k - 1], nums[n - 1]);

		vector<int> vis(n + 1, 0);
		for (int i = 0; i < n - 1; i ++)
			vis[nums[i]] = 1;
		
		int mex = 0;
		while (vis[mex]) mex ++;

		if (nums.back() >= mex) cout << -1 << ' ' << -1 << '\n';
		else cout << k << ' ' << n << '\n';
	}

	return 0;
}