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

	int y, x, r;
	cin >> y >> x >> r;

	x = abs(x);

	if (1ll * x * x * y * y > 1ll * r * r * (x * x + y * y)) cout << -1;
	else if (r >= x) cout << 0;
	else {
		cout << fixed << setprecision(20);
		long double ans = 0;
		ans += asinl((long double)y / hypotl(x, y) / r * x);
		ans -= atan2l(y, x);
		ans /= acos(-1);
		ans *= 180;
		cout << ans;
	}

	return 0;
}