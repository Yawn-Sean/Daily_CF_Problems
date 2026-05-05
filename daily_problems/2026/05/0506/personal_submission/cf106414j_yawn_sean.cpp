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

	int t, step = 2e8 + 5;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<pair<int, int>> pts(n);
		for (auto &[x, y]: pts) cin >> x >> y;

		sort(pts.begin(), pts.end());

		cout << n * 2 + 2 << '\n';
		for (auto &[x, y]: pts) {
			cout << x << ' ' << y << '\n';
			cout << x + 1 << ' ' << y - step << '\n';
		}
		cout << step << ' ' << step << '\n';
		cout << -step << ' ' << step << '\n';
	}

	return 0;
}