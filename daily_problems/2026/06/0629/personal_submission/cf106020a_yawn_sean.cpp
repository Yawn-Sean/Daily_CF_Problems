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

	int n;
	cin >> n;

	vector<vector<int>> path(n);

	for (int i = 0; i < n - 1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	vector<vector<int>> possible(3, vector<int>(n, 1));
	vector<int> ans(n, -1);

	auto dfs = [&] (auto &self, int u) -> void {
		for (auto &v: path[u]) {
			if (ans[v] == -1) {
				possible[ans[u]][v] = 0;

				int c = 0;
				for (int j = 0; j < 3; j ++) c += possible[j][v];

				if (c == 1) {
					for (int j = 0; j < 3; j ++) {
						if (possible[j][v]) {
							ans[v] = j;
							self(self, v);
						}
					}
				}
			}
		}
	};

	for (int i = 0; i < n; i ++) {
		if (ans[i] == -1) {
			int chosen;
			for (int j = 0; j < 3; j ++) {
				if (possible[j][i]) {
					chosen = j;
					break;
				}
			}
			
			for (int j = 0; j < 3; j ++) {
				if (j != chosen) {
					possible[j][i] = 0;
				}
			}

			ans[i] = chosen;
			dfs(dfs, i);
		}
	}

	for (auto &x: ans) cout << (char)('a' + x);

	return 0;
}