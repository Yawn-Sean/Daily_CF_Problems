#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
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

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;
		vector<string> grid1(n), grid2(n);
		for (auto &s: grid1) cin >> s;
		for (auto &s: grid2) cin >> s;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if ((i + j) & 1) {
					grid1[i][j] ^= '#' ^ '.';
					grid2[i][j] ^= '#' ^ '.';
				}
			}
		}

		vector<pair<int, int>> p1, p2;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (grid1[i][j] != grid2[i][j]) {
					if (grid1[i][j] == '#') p1.emplace_back(i, j);
					else p2.emplace_back(i, j);
				}
			}
		}

		if (p1.size() != p2.size()) cout << -1 << '\n';
		else {
			vector<array<int, 4>> ops;

			auto go = [&] (pair<int, int> v1, pair<int, int> v2) -> void {
				auto [x1, y1] = v1;
				auto [x2, y2] = v2;

				int dx = (x2 >= x1 ? 1 : -1);
				int dy = (y2 >= y1 ? 1 : -1);

				int x = x1, y = y1;
				vector<pair<int, int>> cur;
				cur.emplace_back(x, y);

				while (x != x2) {
					x += dx;
					if (grid1[x][y] == '.') {
						cur.emplace_back(x, y);
						for (int i = cur.size() - 1; i > 0; i --) {
							auto [vx1, vy1] = cur[i];
							auto [vx2, vy2] = cur[i - 1];
							swap(grid1[vx1][vy1], grid1[vx2][vy2]);
							ops.push_back({vx1, vy1, vx2, vy2});
						}
						cur.clear();
					}
					cur.emplace_back(x, y);
				}

				while (y != y2) {
					y += dy;
					if (grid1[x][y] == '.') {
						cur.emplace_back(x, y);
						for (int i = cur.size() - 1; i > 0; i --) {
							auto [vx1, vy1] = cur[i];
							auto [vx2, vy2] = cur[i - 1];
							swap(grid1[vx1][vy1], grid1[vx2][vy2]);
							ops.push_back({vx1, vy1, vx2, vy2});
						}
						cur.clear();
					}
					cur.emplace_back(x, y);
				}
			};

			for (int i = 0; i < p1.size(); i ++) go(p1[i], p2[i]);

			cout << ops.size() << '\n';

			for (auto &[x1, y1, x2, y2]: ops)
				cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
		}
	}

	return 0;
}