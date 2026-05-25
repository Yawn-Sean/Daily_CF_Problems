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

	vector<array<int, 7>> items(n);
	for (auto &[d, p, c, lx, rx, ly, ry]: items)
		cin >> d >> p >> c >> lx >> rx >> ly >> ry;

	vector<long double> dp(1 << n, 0);
	vector<long long> cur_time(1 << n, 0);

	for (int i = 0; i < (1 << n); i ++) {
		for (int j = 0; j < n; j ++) {
			if (i >> j & 1) {
				int oi = i ^ (1 << j);
				auto [d, p, c, lx, rx, ly, ry] = items[j];

				cur_time[i] = cur_time[oi] + c;
				long double nval = dp[oi];

				if (cur_time[i] <= d) {
					nval += p;
					if (cur_time[i] <= ly)
						nval += (long double)(lx + rx) / 2;
					else if (cur_time[i] <= ry)
						nval += (long double)(lx + rx) / 2 * (ry - cur_time[i]) / (ry - ly);
				}

				dp[i] = max(dp[i], nval);
			}
		}
	}

	cout << fixed << setprecision(15) << dp.back();

	return 0;
}