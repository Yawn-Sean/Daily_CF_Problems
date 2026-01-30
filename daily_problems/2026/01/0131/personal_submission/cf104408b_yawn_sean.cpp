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

	long double pi = acosl(-1);

	cout << fixed << setprecision(10);

	while (t --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (!x1 && !x2) cout << abs(y1 - y2) << '\n';
		else if (!y1 && !y2) cout << abs(x1 - x2) << '\n';
		else {
			int v1 = abs(x1) + abs(y1);
			int v2 = abs(x2) + abs(y2);

			if (v1 > v2) swap(v1, v2);

			cout << v1 * pi / 2 + v2 - v1 << '\n';
		}
	}

	return 0;
}