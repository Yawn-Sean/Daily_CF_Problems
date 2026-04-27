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

	long long a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a == b) {
		if (c != d) cout << 0;
		else {
			long long v = 2 * c / (2 * a + 1);
			cout << c - a * v;
		}
	}
	else {
		if ((d - c) % (b - a)) cout << 0;
		else {
			long long v = (d - c) / (b - a);
			if (v < 0) cout << 0;
			else if (c - a * v < (v + 1) / 2) cout << 0;
			else cout << c - a * v;
		}
	}

	return 0;
}