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
		int n, q;
		cin >> n >> q;

		vector<vector<pair<int, int>>> path(n);
		
		for (int i = 0; i < n - 1; i ++) {
			int u, v, w;
			cin >> u >> v >> w;
			u --, v --;
			path[u].emplace_back(w, v);
			path[v].emplace_back(w, u);
		}

		vector<int> vals, order;

		auto dfs = [&] (auto &self, int u, int p, int cur) -> void {
			vals.emplace_back(cur);
			order.emplace_back(u);

			sort(path[u].begin(), path[u].end());

			for (auto &[w, v]: path[u]) {
				if (v != p) {
					self(self, v, u, max(cur, w));
				}
			}
		};

		dfs(dfs, 0, -1, 0);

		for (int i = n - 2; i >= 0; i --) vals[i] = min(vals[i], vals[i + 1]);

		long long ans = 0;

		while (q --) {
			int x; cin >> x;
			int p = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
			ans += order[p - 1] + 1;
		}

		cout << ans << '\n';
	}

	return 0;
}