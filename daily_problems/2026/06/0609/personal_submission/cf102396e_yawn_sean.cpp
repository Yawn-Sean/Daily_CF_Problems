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

	int m = 0;
	int cur = 1 << (n - 1);
	vector<int> ans(n);

	for (int i = 0; i < n; i ++) {
		if (nums[i]) {
			ans[i] = cur / nums[i];
			m += cur;
			cur >>= 1;
		}
	}

	for (int i = 0; i < n; i ++) {
		if (!nums[i]) {
			ans[i] = cur;
			cur /= 2;
		}
	}

	cout << m << '\n';
	for (auto &x: ans) cout << x << ' ';

	return 0;
}