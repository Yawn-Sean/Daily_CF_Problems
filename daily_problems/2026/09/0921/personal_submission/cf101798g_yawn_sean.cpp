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

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	sort(nums.rbegin(), nums.rend());

	int k = 31 - __builtin_clz(n), pt = 1;
	long long ans = 1ll * k * nums[0];

	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < (1 << i); j ++) {
			ans += 1ll * nums[pt + j] * (k - i - 2);
		}
		pt += 1 << i;
	}

	cout << ans;

	return 0;
}