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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> path(n + 1);
	for (int i = 0; i < m; i ++) {
		int u, v;
		cin >> u >> v;
		path[u].emplace_back(v);
		path[v].emplace_back(u);
	}

	for (int u = 1; u <= n; u ++) {
		for (auto &v: path[u]) {
			for (int i = 0; i < min(4, (int)path[u].size()); i ++) {
				for (int j = 0; j < min(4, (int)path[v].size()); j ++) {
					int a = path[u][i], b = path[v][j];
					if (a != v && b != u && a != b) {
						cout << a << '\n';
						cout << u << '\n';
						cout << v << '\n';
						cout << b << '\n';
						return 0;
					}
				}
			}
		}
	}

	cout << -1;

	return 0;
}