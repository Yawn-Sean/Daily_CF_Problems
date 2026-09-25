#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	cout << fixed << setprecision(10);

	while (t --) {
		int n;
		long long k;
		cin >> n >> k;

		vector<pair<int, int>> pts(n);
		for (auto &[x, y]: pts) cin >> x >> y;

		long long area = 0;

		for (int i = 0; i < n - 2; i ++) {
			auto [x1, y1] = pts[0];
			auto [x2, y2] = pts[(i + 1) % n];
			auto [x3, y3] = pts[(i + 2) % n];

			int dx1 = x2 - x1, dy1 = y2 - y1;
			int dx2 = x3 - x1, dy2 = y3 - y1;

			area += abs(1ll * dx1 * dy2 - 1ll * dx2 * dy1);
		}

		long double perimeter = 0;

		for (int i = 0; i < n; i ++) {
			auto [x1, y1] = pts[i];
			auto [x2, y2] = pts[(i + 1) % n];
			perimeter += hypot(x1 - x2, y1 - y2);
		}

		if (area >= 2 * k) cout << 0 << '\n';
		else {
			long double a = acosl(-1), b = perimeter, c = (long double)(area - 2 * k) / 2;
			cout << -2 * c / (b + sqrtl(b * b - 4 * a * c)) << '\n';
		}
	}

	return 0;
}