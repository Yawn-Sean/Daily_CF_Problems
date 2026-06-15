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

	int n, ans = 1e9;
	cin >> n;

	while (n --) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		ans = min(ans, min({a + d, b + e, a + c + e, b + c + d}));
	}

	cout << ans;

	return 0;
}