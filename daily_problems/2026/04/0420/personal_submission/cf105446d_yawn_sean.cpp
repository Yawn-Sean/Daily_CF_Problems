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

	int t;
	cin >> t;

	cout << fixed << setprecision(10);

	while (t --) {
		double p, r, y;
		cin >> p >> r >> y;
		double left = -2, right = 2;

		auto f = [&] (double x) -> double {
			return max({abs(x), abs(x - r), abs((p + y + r) / 2 - x), abs((y + r - p) / 2 - x)});
		};

		for (int i = 0; i < 100; i ++) {
			double mid1 = (left * 2 + right) / 3;
			double mid2 = (left + right * 2) / 3;
			if (f(mid1) < f(mid2)) right = mid2;
			else left = mid1;
		}

		double x = (left + right) / 2;

		cout << x << ' ' << (p + y + r) / 2 - x << ' ' << x - r << ' ' << (y + r - p) / 2 - x << '\n';
	}

	return 0;
}