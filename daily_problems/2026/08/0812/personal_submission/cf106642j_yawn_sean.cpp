#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

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
		for (auto &x: nums) cin >> x;

		long long ans = 0, cur = 0;
		vector<array<int, 4>> stk;
		stk.push_back({-1, -1, 0, 0});

		for (int i = 0; i < n; i ++) {
			while (stk.back()[0] > nums[i]) {
				cur -= stk.back()[2];
				stk.pop_back();
			}

			if (stk.back()[0] != nums[i]) {
				stk.push_back({nums[i], i, i - stk.back()[1], 0});
			}
			else {
				auto [val, idx, dp1, dp2] = stk.back(); stk.pop_back();
				cur -= dp1;
				stk.push_back({nums[i], i, dp2 + i - idx, dp1});
			}

			cur += stk.back()[2];
			ans += cur;
		}

		cout << ans << '\n';
	}

	return 0;
}