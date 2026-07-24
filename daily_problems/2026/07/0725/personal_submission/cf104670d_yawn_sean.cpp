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

	int n, m;
	cin >> m >> n;

	vector<string> grid(n);
	for (auto &v: grid) cin >> v;

	string ops;
	cin >> ops;

	int l = ops.size();

	int sx = -1, sy = -1;

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == 'S') {
				sx = i, sy = j;
			}
		}
	}

	vector<pair<int, int>> que;
	vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	vector<vector<int>> dis(n, vector<int>(m, -1));

	que.emplace_back(sx, sy);
	dis[sx][sy] = 0;

	for (int i = 0; i < que.size(); i ++) {
		auto [x, y] = que[i];

		for (auto &[dx, dy]: dirs) {
			if (grid[x + dx][y + dy] == '#') continue;
			if (dis[x + dx][y + dy] == -1) {
				dis[x + dx][y + dy] = dis[x][y] + 1;
				que.emplace_back(x + dx, y + dy);
			}
		}
	}

	map<char, pair<int, int>> mp;
	mp['N'] = {-1, 0};
	mp['S'] = {1, 0};
	mp['W'] = {0, -1};
	mp['E'] = {0, 1};

	vector<vector<int>> ans(n, vector<int>(m, 0));
	ans[sx][sy] = 1;

	for (auto &[x, y]: que) {
		if (ans[x][y]) {
			if (dis[x][y] < l) {
				for (auto &[c, dir]: mp) {
					if (c != ops[dis[x][y]]) {
						auto [dx, dy] = dir;
						if (dis[x + dx][y + dy] == dis[x][y] + 1) {
							ans[x + dx][y + dy] = 1;
						}
					}
				}
			}
			else grid[x][y] = '!';
		}
	}

	for (auto &v: grid) cout << v << '\n';

	return 0;
}