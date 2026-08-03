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
		int n, m;
		cin >> n >> m;

		vector<int> nums(n);
		for (auto &x: nums) cin >> x;

		auto f = [&] (int x) -> long long {
			if (x < 0) return 0;
			int l = 0, r = 0;
			unsigned int cur_sum = 0, cur_xor = 0;
			long long ans = 0;

			while (l < n) {
				r = max(l, r);

				while (cur_sum - cur_xor <= x && r < n) {
					if (r < n - 1) {
						int v = nums[r] ^ nums[r + 1];
						cur_sum += v;
						cur_xor ^= v;
					}
					r ++;
				}

				ans += r - l;

				if (l < n - 1) {
					int v = nums[l] ^ nums[l + 1];
					cur_sum -= v;
					cur_xor ^= v;
				}

				l ++;
			}

			return ans;
		};

		cout << f(m) - f(m - 1) << '\n';
	}

	return 0;
}