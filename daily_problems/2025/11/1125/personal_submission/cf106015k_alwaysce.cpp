#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct DSU {
	int n;
	vector<int> fa, sz;
	
	DSU(int n = 0): fa(n), sz(n, 1) {
		for (int i = 0; i < n; i++) {
			fa[i] = i;
		}
	}
	
	int find(int x) {
		while (x != fa[x]) {
			fa[x] = fa[fa[x]];
			x = fa[x];
		}
		return x;
	}
	
	bool merge(int u, int v) {
		int fu = find(u);
		int fv = find(v);
		if (fu == fv) {
			return false;
		}	
		
		if (sz[fu] > sz[fv]) {
			sz[fu] += sz[fv];
			fa[fv] = fu;
		} else {
			sz[fv] += sz[fu];
			fa[fu] = fv;
		}
		return true;
	}
	
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	vector<array<int, 3>> edges(m), lefts;
	for (auto& [u, v, w]: edges) {
		cin >> u >> v >> w;
		--u; --v;
	}
	
	sort(edges.begin(), edges.end(), [&](const array<int, 3>& x, const array<int, 3>& y) {
		return x[2] < y[2];
	});
	
	// 首先求MST
	DSU d(n);
	vector<vector<pair<int, int>>> mst(n);
	for (int i = 0; i < m; i++) {
		int u = edges[i][0], v = edges[i][1], w = edges[i][2];
		if (d.merge(u, v)) {
			mst[u].emplace_back(v, w);
			mst[v].emplace_back(u, w);
		} else {
			lefts.push_back({u, v, w});
		}
	}
	
	// 接下来对于MST上用倍增处理LCA
	vector<int> dep(n);
	// fa[i][j]: u的 第(1<<j)级别 的祖先
	vector<vector<int>> fa(n, vector<int>(20, -1));
	vector<i64> dist(n);
	
	auto dfs = [&](auto&& dfs, int u, int p) -> void {
		for (auto& [v, w] : mst[u]) {
			if (v != p) {
				dep[v] = dep[u] + 1;
				dist[v] = dist[u] + w;
				fa[v][0] = u;
				dfs(dfs, v, u);
			}
		}
	};
	
	dfs(dfs, 0, -1);
	for (int j = 0; j < 19; j++) {
		for (int i = 0; i < n; i++) {
			if (fa[i][j] != -1) {
				fa[i][j + 1] = fa[fa[i][j]][j];
			}
		}
	}
	
	auto lca = [&](int u, int v) {
		if (dep[u] < dep[v]) {
			swap(u, v);
		}
		int diff = dep[u] - dep[v];
		for (int j = 19; j >= 0; j--) {
			if ((diff >> j) & 1) {
				u = fa[u][j];
			}
		}
		
		if (u == v) {
			return u;
		}
		
		// 跳到正好是LCA的下面一级
		for (int j = 19; j >= 0; j--) {
			if (fa[u][j] != fa[v][j]) {
				u = fa[u][j];
				v = fa[v][j];
			}
		}
		return fa[u][0];
	};
	
	for (auto& [u, v, w]: lefts) {
		int p = lca(u, v);
		i64 d = dist[u] + dist[v] - 2ll * dist[p];
		if (d > w) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	
	return 0;
}
