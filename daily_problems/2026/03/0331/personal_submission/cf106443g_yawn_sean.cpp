#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	vector<set<int>> tmp(n);

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j ++) {
			int msk = 0;
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[j];

			for (int k = 0; k < n; k ++) {
				auto [x, y] = pts[k];
				if (1ll * (x - x1) * (y - y2) == 1ll * (x - x2) * (y - y1)) {
					msk |= 1 << k;
				}
			}

			for (int k = 0; k < n; k ++) {
				if (msk >> k & 1) {
					tmp[k].insert(msk);
				}
			}
		}
	}

	vector<int> dp(1 << n, n);
	dp[0] = 0;

	for (int i = 0; i < (1 << n) - 1; i ++) {
		int x = ((1 << n) - 1) - i;
		int bit = __builtin_ctz(x & -x);
		for (auto &j: tmp[bit]) {
			dp[i | j] = min(dp[i | j], dp[i] + 1);
		}
	}

	cout << dp.back();

	return 0;
}