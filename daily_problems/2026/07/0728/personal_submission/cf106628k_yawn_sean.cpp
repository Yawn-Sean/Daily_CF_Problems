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

	int t, inf = 2e9;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<pair<int, int>> pts;

		for (int i = 0; i < n; i ++) {
			int a, b;
			cin >> a >> b;
			pts.emplace_back(a + b, a - b);
		}

		if (n <= 3) cout << 0 << '\n';
		else {
			vector<int> order1(n), order2(n);
			
			iota(order1.begin(), order1.end(), 0);
			iota(order2.begin(), order2.end(), 0);

			sort(order1.begin(), order1.end(), [&] (int i, int j) {
				return pts[i].first < pts[j].first;
			});
			sort(order2.begin(), order2.end(), [&] (int i, int j) {
				return pts[i].second < pts[j].second;
			});

			vector<int> idxs;

			idxs.emplace_back(order1[0]);
			idxs.emplace_back(order1[1]);
			idxs.emplace_back(order1[n - 2]);
			idxs.emplace_back(order1[n - 1]);

			idxs.emplace_back(order2[0]);
			idxs.emplace_back(order2[1]);
			idxs.emplace_back(order2[n - 2]);
			idxs.emplace_back(order2[n - 1]);

			long long ans = 4e9;

			for (int i = 0; i < 8; i ++) {
				for (int j = 0; j < i; j ++) {
					int i1 = idxs[i], i2 = idxs[j];

					long long mi_x = inf, ma_x = -inf;
					long long mi_y = inf, ma_y = -inf;

					for (int idx = 0; idx < n; idx ++) {
						if (idx != i1 && idx != i2) {
							long long x = pts[idx].first;
							long long y = pts[idx].second;
							mi_x = min(mi_x, x);
							ma_x = max(ma_x, x);
							mi_y = min(mi_y, y);
							ma_y = max(ma_y, y);
						}
					}

					ans = min(ans, max(ma_x - mi_x, ma_y - mi_y));
				}
			}

			cout << ans << '\n';
		}
	}

	return 0;
}