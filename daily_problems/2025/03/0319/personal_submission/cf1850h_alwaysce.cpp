#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int t;
	cin >> t;
	i64 inf = 1e15;
	
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int,int>>> path(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			path[u].emplace_back(v, w);
			path[v].emplace_back(u, -w);
		}	
		
		vector<i64> cur(n + 1, inf);
		bool flag = true;
		function<void(int)> dfs = [&](int u) {
			for (auto&[v, w]: path[u]) {
				if (cur[v] == inf) {
					cur[v] = cur[u] + w;
					dfs(v);
				} else if (cur[v] != cur[u] + w) {
					flag = false;
				}
			}
		};
		
		for (int i = 0; i <= n; i++) {
			if (cur[i] == inf) {
				cur[i] = 0;
				dfs(i);
			}
		}
		
		cout << (flag ? "YES" : "NO") << '\n';
	}
	return 0;
}
