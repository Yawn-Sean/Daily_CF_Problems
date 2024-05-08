#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n + 1);
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> vis(n + 1);
	int cnt = 0;
	vector<int> ans;
	bool ok = false;
	auto dfs = [&](auto self, int x) -> void {
		vis[x] = ++cnt;
		ans.push_back(x);
		for (int y : adj[x]) {
			if (ok) {
				return;
			}
			if (vis[y]) {
				if (cnt - vis[y] < k) {
					continue;
				}
				cout << vis[x] - vis[y] + 1 << '\n';
				for (int i = vis[y]; i <= vis[x]; ++i) {
					cout << ans[i - 1] << ' ';
				}
				cout << '\n';
				ok = true;
				return;
			}
			self(self, y);
		}
	};
	dfs(dfs, 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
