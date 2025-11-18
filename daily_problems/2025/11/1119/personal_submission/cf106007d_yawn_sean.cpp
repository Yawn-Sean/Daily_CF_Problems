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
		int n;
		cin >> n;

		vector<string> grid(n);
		for (auto &s: grid) cin >> s;

		vector<pair<int, int>> ops;
		vector<int> vis(n, 0);

		auto dfs = [&] (auto &self, int u) -> void {
			vis[u] = 1;

			for (int v = 0; v < n; v ++) {
				if (grid[u][v] != '0' && !vis[v]) {
					ops.emplace_back(u, v);
					self(self, v);
				}
			}
		};

		dfs(dfs, 0);

		if (ops.size() + 1 == n) {
			cout << "Yes\n";
			reverse(ops.begin(), ops.end());
			for (auto &[u, v]: ops)
				cout << u + 1 << ' ' << v + 1 << '\n';
		}
		else cout << "No\n";

		if (t) cout << '\n';
	}

	return 0;
}