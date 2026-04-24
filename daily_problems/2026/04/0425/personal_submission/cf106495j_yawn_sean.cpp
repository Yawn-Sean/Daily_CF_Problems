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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		int c0 = n / 2, c1 = n - c0;
		cout << (1ll * c0 * (c0 - 1) * (c0 - 2) / 6 + 1ll * c0 * c1 * (c1 - 1) / 2) % mod << '\n';
	}

	return 0;
}