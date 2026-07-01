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

	int t;
	cin >> t;

	while (t --) {
		int n, c0 = 0, c1 = 0;
		cin >> n;

		long long ans = 1ll * n * (n - 1) / 2;

		while (n --) {
			int x, y;
			cin >> x >> y;

			if (x > y) {
				ans -= c0;
				c0 ++;
			}
			else if (x < y) {
				ans -= c1;
				c1 ++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}