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
		int n, A;
		cin >> n >> A;
		if (2 * A < n - 2) cout << "No\n";
		else {
			cout << "Yes\n";

			if (n % 2 == 0) {
				cout << 0 << ' ' << -2 * A + n - 2 << '\n';
			}
			else {
				cout << 2 << ' ' << -2 * A + n - 3 << '\n';
				cout << 0 << ' ' << 0 << '\n';
			}

			for (int i = 1; i < n / 2; i ++) {
				cout << i % 2 - 1 << ' ' << i << '\n';
			}

			for (int i = n / 2 - 1; i > 0; i --) {
				cout << i % 2 << ' ' << i << '\n';
			}

			cout << 1 << ' ' << 0 << '\n';
		}
	}

	return 0;
}