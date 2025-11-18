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
		int n, q;
		cin >> n >> q;

		string s;
		cin >> s;

		vector<vector<int>> path(n);
		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<int> queries(q);
		for (auto &u: queries)
			cin >> u, u --;

		int rt = queries[0];
		vector<int> parent(n), cols(n, 0);

		auto dfs = [&] (auto &self, int u, int p) -> void {
			parent[u] = p;
			for (auto &v: path[u]) {
				if (v != p) {
					self(self, v, u);
				}
			}
		};

		dfs(dfs, rt, -1);

		int total = n, cnt = n;

		for (int i = 0; i < n; i ++) {
			if (s[i] == '0') {
				int u = i;
				total --;

				while (u >= 0 && !cols[u]) {
					cols[u] = 1;
					cnt --;
					u = parent[u];
				}
			}
		}

		for (auto &u: queries) {
			if (s[u] == '1') {
				s[u] = '0';
				total --;
			}

			while (u >= 0 && !cols[u]) {
				cols[u] = 1;
				cnt --;
				u = parent[u];
			}

			cout << 1ll * cnt * (cnt + 1) / 2 + 1ll * cnt * (total - cnt) << '\n';
		}
	}

	return 0;
}