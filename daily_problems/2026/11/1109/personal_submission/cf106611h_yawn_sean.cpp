#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int hx, hy, cx, cy, d, u;
	cin >> hx >> hy >> cx >> cy >> d >> u;

	long double pi = acosl(-1);

	if (abs(hx - cx) + abs(hy - cy) <= 1) cout << 1;
	else {
		long double mid = atan2l(hy - cy, hx - cx);
		long double delta = asinl(1 / hypotl(hy - cy, hx - cx));

		long double l1 = mid - delta, r1 = mid + delta;
		long double l2 = pi * (d - u) / 180, r2 = pi * (d + u) / 180;

		long double overlap = 0;

		for (int i = -1; i <= 1; i ++) {
			overlap += max((long double)0, min(r1, r2 + i * pi * 2) - max(l1, l2 + i * pi * 2));
		}

		cout << fixed << setprecision(20) << overlap / (pi * 2 * u / 180);
	}

	return 0;
}