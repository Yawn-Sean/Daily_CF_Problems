#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> path(n);
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back(v);
	}
	
	vector<int> vis(n);
	
	function<void(int)> dfs = [&](int u) {
		if (vis[u]) {
			return;
		}
		vis[u] = 1;
		for (auto& v: path[u]) {
			dfs(v);
		}
		cout << u + 1 << ' ';
	};
	
	for (int i = 0; i < n; i++) {
		dfs(i);
	}
	return 0;
}
