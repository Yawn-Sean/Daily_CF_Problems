#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<pair<int, int>> pos(n * n + 1);

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			int x;
			cin >> x;
			pos[x] = {i, j};
		}
	}

	vector<int> c_row(n, 0), c_col(n, 0);

	long long ans = 0;

	for (int i = 1; i <= n * n; i ++) {
		auto [x, y] = pos[i];
		ans += c_row[x] * (n - 1 - c_col[y]);
		ans += c_col[y] * (n - 1 - c_row[x]);
		c_row[x] ++, c_col[y] ++;
	}

	cout << ans / 2;

	return 0;
}