#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

#include "atcoder/dsu.hpp"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> deg(n, 0);

	while (m --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		deg[u] ^= 1;
		deg[v] ^= 1;
	}

	atcoder::dsu uf(n);
	vector<vector<int>> path(n);

	while (k --) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		if (uf.merge(u, v)) {
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}
	}

	vector<pair<int, int>> ops;

	auto dfs = [&] (auto &self, int u, int p) -> int {
		int cur = deg[u];
		for (auto &v: path[u]) {
			if (v != p) {
				cur ^= self(self, v, u);
			}
		}
		if (cur) ops.emplace_back(u, p);
		return cur;
	};

	for (int i = 0; i < n; i ++) {
		if (uf.leader(i) == i && dfs(dfs, i, -1)) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES\n";
	cout << ops.size() << '\n';
	for (auto &[x, y]: ops) cout << x + 1 << ' ' << y + 1 << '\n';

	return 0;
}