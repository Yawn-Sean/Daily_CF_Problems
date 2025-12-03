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

	int t;
	cin >> t;

	cout << fixed << setprecision(10);
	long double pi = acosl(-1);

	while (t --) {
		int r, n, l;
		cin >> r >> n >> l;

		long double ans = 0;
		ans += (long double)l * r * n;
		ans += pi * r * r;
		ans += (long double)l * l / 2 / tanl(pi / n) * n / 2;

		cout << ans << '\n';
	}

	return 0;
}