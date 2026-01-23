#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	vector<vector<int>> acc_13(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> acc_22(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> acc_31(n + 1, vector<int>(m + 1, 0));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j + 2 < m; j ++) {
			if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2]) {
				acc_13[i + 1][j + 1] = 1;
			}
		}
	}

	for (int i = 0; i + 1 < n; i ++) {
		for (int j = 0; j + 1 < m; j ++) {
			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i + 1][j + 1]) {
				acc_22[i + 1][j + 1] = 1;
			}
		}
	}

	for (int i = 0; i + 2 < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j]) {
				acc_31[i + 1][j + 1] = 1;
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= m; j ++) {
			acc_13[i + 1][j] += acc_13[i][j];
			acc_22[i + 1][j] += acc_22[i][j];
			acc_31[i + 1][j] += acc_31[i][j];
		}
	}

	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j < m; j ++) {
			acc_13[i][j + 1] += acc_13[i][j];
			acc_22[i][j + 1] += acc_22[i][j];
			acc_31[i][j + 1] += acc_31[i][j];
		}
	}

	int q;
	cin >> q;

	while (q --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		bool flg = true;

		if (y2 >= y1 + 2 && acc_13[x1][y1] - acc_13[x2 + 1][y1] - acc_13[x1][y2 - 1] + acc_13[x2 + 1][y2 - 1]) flg = false;
		if (x2 > x1 && y2 > y1 && acc_22[x1][y1] - acc_22[x2][y1] - acc_22[x1][y2] + acc_22[x2][y2]) flg = false;
		if (x2 >= x1 + 2 && acc_31[x1][y1] - acc_31[x2 - 1][y1] - acc_31[x1][y2 + 1] + acc_31[x2 - 1][y2 + 1]) flg = false;

		cout << (flg ? "YES" : "NO") << '\n';
	}

	return 0;
}