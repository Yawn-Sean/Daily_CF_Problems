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
		int n, q;
		cin >> n >> q;

		vector<array<int, 3>> updates;

		for (int i = 0; i < q; i ++) {
			int l, r, x, v;
			cin >> l >> r >> x >> v;

			updates.push_back({l, x, -v});
			updates.push_back({r + 1, x, v});
		}

		vector<long long> ans(n);

		for (int i = 19; i >= 0; i --) {
			for (auto &[b, x, v]: updates) {
				if (b >> i & 1) {
					int higher = b & (~((1 << i + 1) - 1)) & x;
					int lower = x & ((1 << i) - 1);
					ans[higher + lower] += (long long)v << i - __popcount(lower);
				}
			}

			for (int j = 0; j < n; j ++) {
				if (j >> i & 1) {
					ans[j ^ (1 << i)] += ans[j];
				}
			}
		}

		for (int i = 0; i < n; i ++) cout << ans[i] << " \n"[i == n - 1];
	}

	return 0;
}