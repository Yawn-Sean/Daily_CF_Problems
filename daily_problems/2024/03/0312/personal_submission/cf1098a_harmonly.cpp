#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	vector<int> s(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	auto dfs = [&](auto self, int x, int fa, int d) -> void {
		for (int y : adj[x]) {
			if (y == fa) continue;
			if (d % 2 == 0) {
				int t = INT_MAX;
				for (int z : adj[y]) {
					if (z == y) continue;
					t = min(t, s[z]);
				}
				s[y] = (t != INT_MAX ? t : s[x]);
			}
			self(self, y, x, d + 1);
		}
	};
	dfs(dfs, 1, -1, 2);

	// for (int i = 1; i <= n; ++i) {
	// 	cout << s[i] << " \n"[i == n];
	// }

	bool ok = true;
	long long ans = s[1];
	auto dfs2 = [&](auto self, int x, int fa) -> void {
		if (!ok) {
			return;
		}
		for (int y : adj[x]) {
			if (y == fa) continue;
			int t = s[y] - s[x];
			if (t < 0) {
				ok = false;
				return;
			}
			ans += t;
			self(self, y, x);
		}
	};
	dfs2(dfs2, 1, -1);
	cout << (ok ? ans : -1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}
