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
		int n, d;
		cin >> n >> d;

		if ((n / 2) * (n / 2) * 2 >= d) {
			cout << "YES\n";

			int x = n / 2 * 2;
			for (int i = 0; i < x; i ++) {
				for (int j = 0; j < x; j ++) {
					cout << i + 1 << ' ' << j + 1 << ' ' << (i + x / 2) % x + 1 << ' ' << (j + x / 2) % x + 1 << '\n';
				}
			}

			if (n & 1) {
				for (int i = 1; i <= n; i ++)
					cout << i << ' ' << n << ' ' << n << ' ' << n + 1 - i << '\n';
				for (int i = 1; i < n; i ++)
					cout << n << ' ' << i << ' ' << n - i << ' ' << n << '\n';
			}
		}
		else cout << "NO\n";
	}

	return 0;
}