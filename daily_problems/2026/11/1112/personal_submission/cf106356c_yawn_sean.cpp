#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> p(n);
		for (auto &x: p) cin >> x;

		vector<vector<int>> path(n + 1);
		for (int i = 0; i < n - 1; i ++) {
			int u, v;
			cin >> u >> v;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<array<int, 3>> ops;

		for (int i = 0; i < n - 1; i ++) {
			vector<int> parent(n + 1, -1);

			auto dfs = [&] (auto &self, int u, int p) -> void {
				parent[u] = p;
				for (auto &v: path[u]) {
					if (v != p) {
						self(self, v, u);
					}
				}
			};

			dfs(dfs, p[i], -1);

			int a = p[i + 1], b = parent[a];

			auto it = find(path[a].begin(), path[a].end(), b);
			path[a].erase(it);

			it = find(path[b].begin(), path[b].end(), a);
			path[b].erase(it);

			while (b != p[i]) {
				ops.push_back({a, b, parent[b]});
				b = parent[b];
			}

			path[a].emplace_back(b);
			path[b].emplace_back(a);
		}

		cout << ops.size() << '\n';
		for (auto &[a, b, c]: ops) cout << a << ' ' << b << ' ' << c << '\n';
	}

	return 0;
}