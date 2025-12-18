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

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto &s: grid) cin >> s;

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == '.') {
				grid[i][j] = 'L';
				
				for (int ni = i + 1; ni < n; ni ++) {
					if (grid[ni][j] == '#') break;
					grid[ni][j] = '*';
				}

				for (int nj = j + 1; nj < m; nj ++) {
					if (grid[i][nj] == '#') break;
					grid[i][nj] = '*';
				}
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == '*') {
				grid[i][j] = '.';
			}
		}
	}

	for (auto &s: grid) cout << s << '\n';

	return 0;
}