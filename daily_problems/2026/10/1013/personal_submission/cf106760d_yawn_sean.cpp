#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> path(n);

		while (m --) {
			int u, v;
			cin >> u >> v;
			u --, v --;
			path[u].emplace_back(v);
			path[v].emplace_back(u);
		}

		vector<vector<int>> vis(n, vector<int>(n, 0));

		for (int u = 0; u < n; u ++) {
			for (auto &v: path[u]) vis[u][v] = 1;
			for (auto &v1: path[u]) {
				for (auto &v2: path[u]) {
					vis[v1][v2] = 1;
				}
			}
		}

		vector<pair<int, int>> ans;
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				if (vis[i][j]) ans.emplace_back(i, j);
			}
		}

		cout << ans.size() << '\n';
		for (auto &[x, y]: ans) cout << x + 1 << ' ' << y + 1 << '\n';
	}

	return 0;
}