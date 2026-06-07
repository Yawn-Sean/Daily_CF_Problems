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

	int n, x, y;
	cin >> n >> x >> y;

	vector<pair<long double, int>> tmp;

	for (int i = 0; i < n; i ++) {
		int x0, y0, r;
		cin >> x0 >> y0 >> r;
		x0 -= x, y0 -= y;
		tmp.emplace_back(hypotl(x0, y0) - r, r);
	}

	sort(tmp.begin(), tmp.end());

	long double ans = 0;
	long long cur = 0;

	for (auto &[a, b]: tmp) {
		ans = max(ans, a - cur);
		cur += b;
	}

	cout << fixed << setprecision(15) << ans;

	return 0;
}