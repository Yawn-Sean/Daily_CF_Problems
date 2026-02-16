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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<pair<int, int>> path(n + 1);
		path[0].first = 1, path[0].second = 0;

		for (int i = 1; i <= n; i ++)
			cin >> path[i].first >> path[i].second;

		vector<int> sz(n + 1, 0);
		auto dfs = [&] (auto &self, int u, int p) -> void {
			if (path[u].first) {
				self(self, path[u].first, u);
				sz[u] += sz[path[u].first] + 2;
				self(self, path[u].second, u);
				sz[u] += sz[path[u].second] + 2;
			}
		};

		dfs(dfs, 1, 0);

		auto dfs1 = [&] (auto &self, int u, int p) -> void {
			if (path[u].first) {
				sz[path[u].first] += sz[u] + 1;
				sz[path[u].first] %= mod;
				self(self, path[u].first, u);
				sz[path[u].second] += sz[u] + 1;
				sz[path[u].second] %= mod;
				self(self, path[u].second, u);
			}
		};

		dfs1(dfs1, 1, 0);

		for (int i = 1; i <= n; i ++) cout << (sz[i] + 1) % mod << ' ';
		cout << '\n';
	}

	return 0;
}