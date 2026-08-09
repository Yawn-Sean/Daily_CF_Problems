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

	int n, m, k;
	cin >> n >> m >> k;

	if (n == 1) {
		cout << "YES\n";
		for (int i = 0; i < m; i ++) cout << min(i, k - 1) % 2;
		cout << '\n';
	}
	else if (m == 1) {
		cout << "YES\n";
		for (int i = 0; i < n; i ++) cout << min(i, k - 1) % 2 << '\n';
	}
	else if (k == n * m - 1) cout << "NO\n";
	else {
		vector<vector<int>> grid(n, vector<int>(m));

		if (k <= m) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					grid[i][j] = min(j, k - 1) % 2;
				}
			}
		}
		else {
			int first = (k - 1) / m + 1;

			for (int i = 0; i < first; i ++) {
				for (int j = 0; j < m; j ++) {
					if (i * m + j <= k) grid[i][j] = (i + j) % 2;
					else grid[i][j] = 1 - (i + j) % 2;
				}
			}

			for (int i = first; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					grid[i][j] = grid[i - 1][j];
				}
			}

			if (k % m == m - 1) grid[first - 1][m - 1] = grid[first - 2][m - 1];
		}

		cout << "YES\n";
		for (auto &x: grid) {
			for (auto &y: x) cout << y;
			cout << '\n';
		}
	}

	return 0;
}