#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

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
		for (auto &x: nums) cin >> x;

		long long ans = 1ll * n * (n - 1) / 2 - 1, cur;

		cur = 0;
		for (int i = 0; i < n; i ++) {
			ans = max(ans, cur - nums[i]);
			cur += nums[i];
		}

		cur = 0;
		for (int i = n - 1; i >= 0; i --) {
			ans = max(ans, cur - nums[i]);
			cur += nums[i];
		}

		cout << ans << '\n';
	}

	return 0;
}