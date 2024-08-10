#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
	int n;
	cin >> n;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	vector<int> ans;
	auto dfs = [&](auto &&self, int u, int p) -> int {
		int siz = 1;
		for (auto [v, i] : adj[u]) {
			if (v != p) {
				int x = self(self, v, u);
				if (x == -1) {
					return -1;
				}
				if (x == 3) {
					ans.push_back(i);
				} else {
					siz += x;
				}
			}
		}
		return siz <= 3 ? siz : -1;
	};
	if (dfs(dfs, 0, -1) != 3) {
		cout << -1 << "\n";
		return;
	}

	cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i] << " \n"[i == (int)ans.size() - 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
