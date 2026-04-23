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
	long double px, py;
	cin >> n >> px >> py;

	vector<array<long double, 3>> circles(n);
	for (auto &[x, y, r]: circles) cin >> x >> y >> r;

	long double ans = 1e14, eps = 1e-6;

	auto check = [&] (long double x, long double y) -> void {
		for (auto &[x0, y0, r0]: circles) {
			if ((x - x0) * (x - x0) + (y - y0) * (y - y0) > r0 * r0 + eps) return ;
		}
		ans = min(ans, (x - px) * (x - px) + (y - py) * (y - py));
	};

	check(px, py);

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			auto [x1, y1, r1] = circles[i];
			auto [x2, y2, r2] = circles[j];

			long double dx = x2 - x1, dy = y2 - y1, dis = dx * dx + dy * dy;

			if (dis < (r1 - r2) * (r1 - r2) + eps || dis > (r1 + r2) * (r1 + r2) - eps || dis < eps) continue;

			long double tmp = r1 * r1 - r2 * r2 + dis;

			long double midx = x1 + tmp * dx / dis / 2;
			long double midy = y1 + tmp * dy / dis / 2;

			long double val = max((long double)0, 4 * r1 * r1 * dis - tmp * tmp);

			long double tmpx = -sqrtl(val) * dy / dis / 2;
			long double tmpy = sqrtl(val) * dx / dis / 2;

			check(midx + tmpx, midy + tmpy);
			check(midx - tmpx, midy - tmpy);
		}
	}

	for (auto &[x0, y0, r0]: circles) {
		if ((px - x0) * (px - x0) + (py - y0) * (py - y0) > r0 * r0 - eps) {
			long double dx = px - x0, dy = py - y0;
			long double ratio = r0 / hypot(dx, dy);
			check(x0 + ratio * dx, y0 + ratio * dy);
		}
	}

	cout << fixed << setprecision(15) << sqrtl(ans);

	return 0;
}