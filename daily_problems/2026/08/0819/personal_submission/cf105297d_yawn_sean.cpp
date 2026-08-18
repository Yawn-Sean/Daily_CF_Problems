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

	long double x, y, z, tx, ty, tz, R;
	cin >> x >> y >> z >> tx >> ty >> tz >> R;

	tx = max(tx, x - tx), ty = max(ty, y - ty), tz = max(tz, z - tz);

	long double l = 0, r = min({x, y, z}) / 2;

	for (int i = 0; i < 100; i ++) {
		long double mid = (l + r) / 2;

		if ((tx - mid) * (tx - mid) + (ty - mid) * (ty - mid) + (tz - mid) * (tz - mid) >= (mid + R) * (mid + R)) l = mid;
		else r = mid;
	}

	cout << setprecision(15) << fixed << (l + r) / 2 << endl;

	return 0;
}