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

	int t;
	cin >> t;

	while (t --) {
		int r, c, m, k;
		cin >> r >> c >> m >> k;

		if (k > min(r, c)) cout << "NO\n";
		else if (m < k || m > 1ll * max(r, c) * k) cout << "NO\n";
		else {
			vector<string> grid(r, string(c, '.'));
			for (int i = 0; i < k; i ++) grid[i][i] = '#', m --;

			for (int i = 0; i < (r < c ? k : r); i ++) {
				for (int j = 0; j < (c < r ? k : c); j ++) {
					if (m && grid[i][j] == '.') {
						grid[i][j] = '#';
						m --;
					}
				}
			}

			cout << "YES\n";
			for (auto &x: grid) cout << x << '\n';
		}
	}

	return 0;
}