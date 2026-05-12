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

	string rgb = "RGB";
	vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> pts(3);
		int vis = 0;

		for (auto &[x, y]: pts) {
			cin >> x >> y;
			x --, y --;
			vis |= 1 << ((x + y) % 2);
		}

		vector<vector<int>> ans(n, vector<int>(m));
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ans[i][j] = (i + j) % 2;
			}
		}

		if (vis == 3) {
			vis = 0;
			for (auto &[x, y]: pts) {
				if (vis >> ((x + y) % 2) & 1) ans[x][y] = 2;
				vis |= 1 << ((x + y) % 2);
			}

			cout << "YES\n";
			for (auto &x: ans) {
				for (auto &y: x) cout << rgb[y];
				cout << '\n';
			}
		}
		else {
			bool flg = false;

			for (int i = 0; i < 3 && !flg; i ++) {
				for (int j = 0; j < i && !flg; j ++) {
					auto [x1, y1] = pts[i];
					auto [x2, y2] = pts[j];

					if (abs(x1 - x2) + abs(y1 - y2) > 2) {
						ans[x1][y1] = 2;
						ans[x2][y2] ^= 1;

						for (auto &[dx, dy]: dirs) {
							if (x2 + dx >= 0 && x2 + dx < n && y2 + dy >= 0 && y2 + dy < m) {
								ans[x2 + dx][y2 + dy] = 2;
							}
						}
						flg = true;
					}
				}
			}

			if (flg) {
				cout << "YES\n";
				for (auto &x: ans) {
					for (auto &y: x) cout << rgb[y];
					cout << '\n';
				}
			}
			else cout << "NO\n";
		}
	}

	return 0;
}