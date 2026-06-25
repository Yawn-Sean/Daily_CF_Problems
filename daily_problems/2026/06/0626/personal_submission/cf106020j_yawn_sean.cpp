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
		int n, k;
		cin >> n >> k;

		if (n == 2) {
			if ((k & -k) == k) cout << 1;
			else cout << 0;
		}
		else {
			int v = k - n;
			if (n % 2 == 0 && k - n == n / 2 + 1) cout << 1;
			else cout << max(0, n - 1 - 2 * v);
		}
		cout << '\n';
	}

	return 0;
}