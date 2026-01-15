#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
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

	long double a, b, pi = acosl(-1);
	cin >> a >> b;

	long double v = 4 * b * b * sinl(pi / 4);

	cout << fixed << setprecision(15);
	if (a >= v) cout << v;
	else {
		long double theta = asinl(a / 4 / b / b) / 2;
		long double w = b * sinl(theta);
		cout << w * w / tanl(pi / 8) * 8;
	}

	return 0;
}