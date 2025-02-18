#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	std::vector<std::vector<int>> diameters(n);
	
	std::vector<int> d(n, -n - 1), fa(n, -1), q(n * 2);

	for (int i = 0; i < n; i++) {
		// 之前没有被访问过的(树)
		if (d[i] == -n - 1) {
			int l, r;
			l = 0, r = 1;
			q[l] = i; d[i] = -1;
			while (l < r) {
				int u = q[l++]; // q.popfront(u)
				for (auto& v: g[u]) {
					if (d[v] == -n - 1) {
						d[v] = d[u] - 1; // u->v->... d值减小
						q[r++] = v; // q.pushback(v)
					}
				}
			}
			int x; // 走到了树上的某直径的一头x
			x = q[l - 1];
			l = 0, r = 1;
			q[l] = x, d[x] = 0; // d[x]=0
			while (l < r) {
				int u = q[l++];
				for (auto& v: g[u]) {
					if (d[v] < 0) { // u->v往回走
						d[v] = d[u] + 1;
						fa[v] = u;
						q[r++] = v;
					}
				}
			}
			x = q[l - 1];
			int di = d[x];
			for (int j = 0; j < di / 2; j++) {
				x = fa[x];
			}
			// 直径中点x
			diameters[di].push_back(x);				
		}
	}
	
	std::vector<std::pair<int,int>> outs;
	int cur = -1, ma = 0;
	// diameters里面每一个直径对应的树由一个点x代表
	// 倒序模拟这些树的合并
	// 两棵树中，在合并前直径更大的树的中间点，在新树中也一定为中间点
	for (int i = n - 1; i >= 0; i--) {
		for (auto& u: diameters[i]) {
			if (cur == -1) {
				cur = u;
				ma = i;
			} else {
				outs.push_back({cur, u});
				ma = std::max(ma, (i + 1) / 2 + (ma + 1) / 2 + 1); // dx+dy+1
			}
		}
	}
	std::cout << ma << '\n';
	for (auto& [x, y]: outs) {
		std::cout << x + 1 << ' ' << y + 1 << '\n';
	}
	return 0;
}
