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

	unordered_map<int, vector<string>> d;

	d[1] = {
		".",
	};

	d[2] = {
		"#.",
		"#."
	};
	
	d[3] = {
		"#.#",
		"#.#",
		"..."
	};

	d[4] = {
		"#.##",
		"#...",
		"...#",
		"##.#"
	};

	d[5] = {
		"##.##",
		".....",
		"##.##",
		".....",
		"##.##"
	};

	d[6] = {
		"##.#.#",
		"...#.#",
		"##....",
		"....##",
		"#.#...",
		"#.#.##"
	};

	while (t --) {
		int n;
		cin >> n;

		int v = (n - 1) % 6 + 1;

		vector<string> ans(n, string(n, '.'));

		for (int i = n - v; i < n; i ++) {
			for (int j = n - v; j < n; j ++) {
				ans[i][j] = d[v][i - (n - v)][j - (n - v)];
			}
		}

		if (n & 1) {
			for (int i = 0; i < n - v; i += 3) {
				for (int j = 0; j < n; j += 2) {
					ans[i][j] = '#';
					ans[i + 1][j] = '#';
				}
			}
		}
		else {
			for (int i = 0; i < n - v; i += 2) {
				ans[i][0] = '#';
				ans[i][1] = '#';
			}

			for (int i = 0; i < n - v; i += 3) {
				for (int j = 3; j < n; j += 2) {
					ans[i][j] = '#';
					ans[i + 1][j] = '#';
				}
			}
		}

		if (v & 1) {
			for (int i = n - v; i < n; i += 2) {
				for (int j = 0; j < n - v; j += 3) {
					ans[i][j] = '#';
					ans[i][j + 1] = '#';
				}
			}
		}
		else {
			for (int j = 0; j < n - v; j += 2) {
				ans[n - v][j] = '#';
				ans[n - v + 1][j] = '#';
			}

			for (int i = n - v + 3; i < n; i += 2) {
				for (int j = 0; j < n - v; j += 3) {
					ans[i][j] = '#';
					ans[i][j + 1] = '#';
				}
			}
		}

		for (auto &x: ans) cout << x << '\n';
	}

	return 0;
}