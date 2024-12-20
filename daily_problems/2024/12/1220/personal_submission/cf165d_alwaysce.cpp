#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		树上路径 = dep[u]+dep[v]-2*dep[lca(u,v)]
		lca = 倍增
		
		检查白色边 = 给白色边一个权重1
		x -> y路径上没有白色边
		= query(x->lca(x,y)) + query(lca(x,y)->y) == 0
		
		lca(x,y)子树 x/y内部的白色边权重检查 = dfs序 变成连续区间
		只要 prefix(ls[lca], ls[x]) + prefix(ls[lca], ls[y]) == 0
		
	*/
	int n;
	cin >> n;
	
	vector<int> us(n - 1), vs(n - 1);
	vector<vector<int>> path(n);
	
	for (int i = 0; i < n - 1; i++) {
		cin >> us[i] >> vs[i];
		--us[i]; --vs[i];
		path[us[i]].push_back(vs[i]);
		path[vs[i]].push_back(us[i]);
	}
	
	// dfs_order;
	int ts = 0;
	vector<int> ls(n), rs(n), dep(n, 0);
	
	// LCA
	// ceil(log2(1e5))=17
	vector<vector<int>> parent(18, vector<int>(n, -1));
	
	function<void(int, int)> dfs = [&](int u, int fa) {
		parent[0][u] = fa;
		ls[u] = ts++;
		for (auto& v: path[u]) {
			if (v != fa) {
				dep[v] = dep[u] + 1;
				dfs(v, u);
			}
		}
		rs[u] = ts;
	};
	
	dfs(0, -1);
	
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < n; j++) {
			if (parent[i][j] != -1) {
				parent[i + 1][j] = parent[i][parent[i][j]];
			}
		}
	}
	
	function<int(int,int)> lca = [&](int u, int v) {
		if (dep[u] > dep[v]) { swap(u, v); }
		int diff = dep[v] - dep[u]; // 深度差
		while (diff) {
			int lb = diff & -diff;
			int bit = 31 - __builtin_clz(lb); // 深度差 按lowbit1 倍增处理
			v = parent[bit][v]; // v向上走2^bit层
			diff -= lb;
		}
		if (u == v) {
			return u;
		}
		
		// (u, v)在同一层了
		for (int i = 17; i >= 0; i--) {
			if (parent[i][u] != parent[i][v]) {
				u = parent[i][u];
				v = parent[i][v];
			}
		}
		return parent[0][u];
	};
	// [l, r)
	Fenwick<int> fen(n + 1);
	
	int q;
	cin >> q;	
	while (q--) {
		int op;
		cin >> op;
		if (op <= 2) {
			int eid;
			cin >> eid;
			--eid;
			// cout << eid << ' ' << us[eid] << ' ' << vs[eid] << '\n';
			int u = (dep[us[eid]] > dep[vs[eid]] ? us[eid]: vs[eid]);
			// cout << "Add " << ls[u] << ' ' << rs[u] << '\n';
			if (op == 1) {
				// [l, r]
				fen.add(ls[u], -1);
				fen.add(rs[u], 1);
			} else {
				fen.add(ls[u], 1);
				fen.add(rs[u], -1);
			}
			
		} else {
			int u, v;
			cin >> u >> v;
			--u; --v;
			
			int lc = lca(u, v);
            
			int white = fen.rangeSum(0, ls[u]+1) + fen.rangeSum(0, ls[v]+1) - 2 * fen.rangeSum(0, ls[lc] + 1);
			if (white != 0) {
				cout << -1 << endl;
			} else {
				cout << dep[u] + dep[v] - 2 * dep[lc] << endl;
			}
		}
	}
	return 0;
}
