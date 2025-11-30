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

	vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> grid(n, vector<int>(m));
		int res = 0;

		vector<array<int, 3>> tmp;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cin >> grid[i][j];
				res ^= (grid[i][j] & 1);
				tmp.push_back({grid[i][j], i, j});
			}
		}

		sort(tmp.begin(), tmp.end());

		vector<vector<int>> to_fill(n, vector<int>(m, -1));

		for (auto &[v, i, j]: tmp) {
			int val = -1;
			for (auto &[di, dj]: dirs) {
				if (i + di >= 0 && i + di < n && j + dj >= 0 && j + dj < m) {
					val = max(val, to_fill[i + di][j + dj]);
				}
			}

			to_fill[i][j] = val + 1;
			res ^= (val + 1) & 1;
		}

		cout << (res ? "Yes" : "No") << '\n';
	}

	return 0;
}