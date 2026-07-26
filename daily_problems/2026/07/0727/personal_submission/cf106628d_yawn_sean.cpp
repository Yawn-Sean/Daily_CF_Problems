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

	int t, rnd = rng();
	cin >> t;

	while (t --) {
		int n, k;
		cin >> n >> k;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		int l = 0, r = 29;

		while (l <= r) {
			int mid = (l + r) / 2;

			int msk = (1 << mid) - 1;
			unordered_map<int, int> cnt;

			for (auto &v: nums)
				cnt[(v & msk) ^ rnd] ++;
			
			int max_cnt = 0;
			for (auto &[k, v]: cnt) max_cnt = max(max_cnt, v);

			if (max_cnt >= k) l = mid + 1;
			else r = mid - 1;
		}

		cout << ((long long)(k - 1) << r) << '\n';
	}

	return 0;
}