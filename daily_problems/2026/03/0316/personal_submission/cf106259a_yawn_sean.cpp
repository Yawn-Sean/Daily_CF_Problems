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

	while (t --) {
		int n, m, x1, y1, x2, y2;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;

		if ((n * m) & 1) cout << "NO\n";
		else if (min(n, m) == 1) {
			if (m == 1) {
				swap(n, m);
				swap(x1, y1);
				swap(x2, y2);
			}
			if (y1 > y2) swap(y1, y2);

			cout << ((y1 - 1) % 2 == 0 && (y2 - y1 - 1) % 2 == 0 && (m - y2) % 2 == 0 ? "YES\n" : "NO\n");
		}
		else cout << (((x1 + y1 + x2 + y2) & 1) ? "YES\n" : "NO\n");
	}

	return 0;
}