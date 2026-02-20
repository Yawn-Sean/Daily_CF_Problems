#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<vector<pair<int, int>>> path(n);

		while (m --) {
			int u, v, c;
			cin >> u >> v >> c;
			u --, v --, c --;
			path[u].emplace_back(v, c);
		}

		vector<vector<int>> cols(2, vector<int>(n, -2));
		cols[0][0] = -1;
		cols[1][0] = -1;

		auto dfs = [&] (auto &self, int u, int cur) -> void {
			for (auto &[v, c]: path[u]) {
				if (cols[cur][u] != c) {
					if (cols[0][v] == -2) {
						cols[0][v] = c;
						self(self, v, 0);
					}
					else if (cols[0][v] == c) continue;
					else if (cols[1][v] == -2) {
						cols[1][v] = c;
						self(self, v, 1);
					}
				}
			}
		};

		dfs(dfs, 0, 0);

		for (int i = 0; i < n; i ++) {
			if (cols[0][i] != -2) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}