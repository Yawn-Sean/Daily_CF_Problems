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
		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> lines(n);
		for (auto &[k, b]: lines) cin >> k >> b;

		bool flg = true, single = false;
		int x;
		long long y;

		for (int i = 1; i < n; i ++) {
			auto [k1, b1] = lines[0];
			auto [k2, b2] = lines[i];
			if (k1 == k2) {
				if (b1 != b2) flg = false;
			}
			else {
				single = true;

				x = -(b2 - b1) / (k2 - k1);
				y = 1ll * k1 * x + b1;
			}
		}

		if (single) {
			for (int i = 0; i < n; i ++) {
				auto [k, b] = lines[i];
				if (y != 1ll * k * x + b) {
					flg = false;
				}
			}
		}

		if (m) {
			while (m --) {
				int x0;
				cin >> x0;
				if (single && x0 != x) {
					flg = false;
				}
			}
		}
		else flg = true;

		cout << (flg ? "YES" : "NO") << '\n';
	}

	return 0;
}