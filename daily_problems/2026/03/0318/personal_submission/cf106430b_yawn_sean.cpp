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
		int x, y;
		cin >> x >> y;

		if (x == y) cout << "0\n";
		else if (x < y) {
			int ans = 0;
			while (x < y) {
				x *= 2;
				ans ++;
			}
			cout << ans << '\n';
		}
		else {
			if (y <= 2) cout << "-1\n";
			else {
				int ans = 0;
				while (x > y) {
					x = 2 * x / 3 + 1;
					ans ++;
				}
				cout << ans << '\n';
			}
		}
	}

	return 0;
}