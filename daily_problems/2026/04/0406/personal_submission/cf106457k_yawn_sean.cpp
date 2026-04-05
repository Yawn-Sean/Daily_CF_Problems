#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/dsu"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> dirs(300);
	dirs['N'] = {-1, 0};
	dirs['S'] = {1, 0};
	dirs['W'] = {0, -1};
	dirs['E'] = {0, 1};

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto &s: grid) cin >> s;

	string op;
	cin >> op;

	atcoder::dsu uf(n * n + 1);
	auto f = [&] (int i, int j) {return i * n + j;};

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (grid[i][j] == 'S') uf.merge(f(i, j), n * n);
			else if (grid[i][j] == '.') {
				int x = i, y = j;

				for (auto &ch: op) {
					auto [dx, dy] = dirs[ch];
					int nx = x + dx, ny = y + dy;

					if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != '#') {
						x = nx, y = ny;
						if (grid[x][y] == 'S') break;
					}
				}

				uf.merge(f(i, j), f(x, y));
			}
		}
	}

	vector<string> ans(n, string(n, '0'));

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (uf.leader(f(i, j)) == uf.leader(n * n)) {
				ans[i][j] = '1';
			}
		}
	}

	for (auto &x: ans) cout << x << '\n';

	return 0;
}