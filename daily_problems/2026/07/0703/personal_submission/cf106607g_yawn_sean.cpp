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
		long long n, m, k;
		cin >> n >> m >> k;

		long long ans = n;

		if ((n - k) % 2) ans --;
		ans = min(ans, k);
		if (m % 2 == 0) ans = min(ans, n * m - k);

		cout << ans << '\n';
	}

	return 0;
}