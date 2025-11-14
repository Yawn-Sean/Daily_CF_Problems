#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, xl, yl, xr, yr, w, h;
	cin >> n >> xl >> yl >> w >> h;

	xr = xl + w, yr = yl + h;
	xl --, yl --;

	long long g = 0;

	for (int i = 1; i <= 1'000'000; i ++) {
		long long v = n - 1ll * i * i;
		if (v < 0) break;
		long long l = 0, r = 1e9;
		while (l <= r) {
			long long mid = (l + r) / 2;
			if (mid * mid >= v) r = mid - 1;
			else l = mid + 1;
		}
		long long w = l;
		if (w * w == v) {
			g = gcd(g, i);
			g = gcd(g, w);
		}
	}

	long long ans = 0;

	if (g) {
		auto div = [&] (long long x, long long y) -> long long {
			long long res = x / y;
			if (res * y > x) res --;
			return res;
		};

		ans += (div(xr, 2 * g) - div(xl, 2 * g)) * (div(yr, 2 * g) - div(yl, 2 * g));
		ans += (div(xr - g, 2 * g) - div(xl - g, 2 * g)) * (div(yr - g, 2 * g) - div(yl - g, 2 * g));
	}
	else if (xl < 0 && xr >= 0 && yl < 0 && yr >= 0) ans ++;

	cout << ans;

	return 0;
}