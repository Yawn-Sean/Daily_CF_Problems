#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> path(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		path[u].emplace_back(v, w);
		path[v].emplace_back(u, w);
	}
	
	vector<int> colors(n, -1);
	bool ok = true;
	int ans = 0;
	
	function<void(int)> dfs = [&](int u) {
		ans += colors[u];
		for (auto& pr: path[u]) {
			int v = pr.first;
			int w = pr.second;
			
			if (colors[v] == -1) {
				colors[v] = colors[u] ^ w ^ 1;
				dfs(v);
				
			} else if ((colors[u] ^ colors[v] ^ w) != 1) {
				ok = false;
			}
		}
	};
	
	for (int i = 0; i < n; i++) {
		if (colors[i] == -1) {
			colors[i] = 0;
			dfs(i);
		}	
	}
	
	if (ok) {
		cout << ans << '\n';
		for (int i = 0; i < n; i++) {
			if (colors[i] != 0) {
				cout << i + 1 << ' ';
			}
		}
	} else {
		cout << "Impossible";
	}
	
	return 0;
}
