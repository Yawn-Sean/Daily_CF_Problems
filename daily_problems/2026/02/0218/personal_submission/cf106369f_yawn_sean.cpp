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

	int b1, b2, h;
	cin >> b1 >> b2 >> h;

	auto f = [&] (long double x) -> long double {
		vector<long double> tmp = {
			b1 * x,
			b2 * (h - x),
			((b1 + b2) * h - b1 * x - b2 * (h - x)) / 2
		};

		return *max_element(tmp.begin(), tmp.end()) - *min_element(tmp.begin(), tmp.end());
	};

	long double l = 0, r = h;

	for (int i = 0; i < 100; i ++) {
		long double mid1 = (l * 2 + r) / 3;
		long double mid2 = (l + r * 2) / 3;

		if (f(mid1) < f(mid2)) r = mid2;
		else l = mid1;
	}

	cout << fixed << setprecision(20) << f((l + r) / 2) / 2;

	return 0;
}