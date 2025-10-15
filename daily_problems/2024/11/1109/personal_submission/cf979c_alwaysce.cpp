#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		b[i1], b[i2]
		
		- 长度=k
		- i1, i2位于相邻的循环节
		- b[i1] <= b[i2] 成立
		按照循环节内的大小排序
	*/
	int n, x, y;
	cin >> n >> x >> y;
	--x; --y;
	vector<vector<int>> path(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		path[u].push_back(v);
		path[v].push_back(u);
	}
	
	/*
		sz - x子树 * (y所在子树.sz - 1) 是不能选的
		n * (n - 1) - 不能选的
		x 
	*/
	
	vector<int> sz(n), has_y(n);
	
	function<int(int,int)> dfs = [&](int u, int p) {
		sz[u] = 1;
		if (u == y) {
			has_y[u] = 1;
		}
		for (auto& v: path[u]) {
			if (v == p) continue;
			sz[u] += dfs(v, u);
			has_y[u] |= has_y[v];
		}
		return sz[u];
	};
	
	dfs(x, -1);
	
	i64 ans = 1ll * n * (n - 1);
	for (auto& v: path[x]) {
		if (has_y[v]) {
			ans -= 1ll * (sz[x] - sz[v]) * sz[y];
			break;
		}
	}
	cout << ans;
	
    return 0;
}
