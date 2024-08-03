#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	vector<vector<int>> adj(n + 1);
	int _xor = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		_xor ^= a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cnt = 0;
	auto dfs = [&](auto self, int x, int fa) -> int {
		int val = a[x];
		for (int y : adj[x]) {
			if (y == fa) continue;
			val ^= self(self, y, x);
		}
		if (val == _xor) {
			++cnt;
			return 0;
		}
		return val;
	};
	if (_xor == 0) {
		cout << "YES\n";
		return;
	}
	if (k == 2) {
		cout << "NO\n";
		return;
	}
	if (dfs(dfs, 1, -1) == 0 && cnt >= 3) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
