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

	vector<int> nums(n * (n - 1) / 2);

	for (auto &x: nums) cin >> x;

	sort(nums.begin(), nums.end());

	long long mn = 0, mx = 0;

	for (int i = 1; i < n; i ++) {
		mn += nums[i - 1];
		mx += nums[i * (i - 1) / 2];
	}

	cout << mn << ' ' << mx << '\n';

	return 0;
}