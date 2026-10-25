#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n, string(m, '.'));

	for (int i = 1; i < n; i += 2) {
		for (int j = 1; j < m; j += 2) {
			cout << "? " << i + 1 << ' ' << j + 1 << endl;
			cin >> grid[i][j];

			switch (grid[i][j]) {
				case 'L':
					grid[i][j + 1] = 'R';
					break;
				case 'R':
					grid[i][j - 1] = 'L';
					break;
				case 'U':
					grid[i + 1][j] = 'D';
					break;
				case 'D':
					grid[i - 1][j] = 'U';
					break;
				default:
					break;
			}
		}
	}

	vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	string chrs = "URDL";

	vector<vector<int>> degs(n, vector<int>(m, 0));
	vector<pair<int, int>> stk;

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] != '.') continue;

			for (auto &[di, dj]: dirs) {
				if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m && grid[i + di][j + dj] == '.') {
					degs[i][j] ++;
				}
			}
			if (degs[i][j] == 1) stk.emplace_back(i, j);
		}
	}

	while (!stk.empty()) {
		auto [x, y] = stk.back(); stk.pop_back();

		if (grid[x][y] == '.') {
			for (int i = 0; i < 4; i ++) {
				auto [dx, dy] = dirs[i];

				if (x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m && grid[x + dx][y + dy] == '.') {
					grid[x][y] = chrs[i ^ 2];
					grid[x + dx][y + dy] = chrs[i];

					degs[x][y] --;
					degs[x + dx][y + dy] --;

					int nx = x + dx, ny = y + dy;

					for (auto &[ndx, ndy]: dirs) {
						if (nx + ndx >= 0 && nx + ndx < n && ny + ndy >= 0 && ny + ndy < m && grid[nx + ndx][ny + ndy] == '.') {
							degs[nx + ndx][ny + ndy] --;
							if (degs[nx + ndx][ny + ndy] == 1) {
								stk.emplace_back(nx + ndx, ny + ndy);
							}
						}
					}
				}
			}
		}
	}

	cout << '!' << '\n';
	for (auto &x: grid) cout << x << '\n';

	return 0;
}