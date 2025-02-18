#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, q;
	std::cin >> n >> q;
	
	std::vector<int> p(n);
	std::vector<std::vector<int>> path(n);
	
	for (int i = 1; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
		path[p[i]].push_back(i);
	}
	
	std::vector<int> dep(n), order, stk = {0};
	while (stk.size()) {
		int u = stk.back();
		stk.pop_back();
		order.emplace_back(u);
		for (auto& v: path[u]) {
			dep[v] = dep[u] + 1;
			stk.emplace_back(v);
		}
	}
	
	std::vector<int> size(n, 1), chains(n);
	std::iota(chains.begin(), chains.end(), 0);
	
	for (int i = n - 1; i > 0; i--) {
		size[p[order[i]]] += size[order[i]];
	}
	
	for (auto& u: order) {
		if (path[u].size()) {
			int mx = -1;
			for (auto& v: path[u]) {
				if (mx == -1 or size[v] >= size[mx]) {
					mx = v;
				}
			}
			chains[mx] = chains[u];
		}
	}
	
	std::function<int(int,int)> lca = [&](int u, int v) -> int {
		while (chains[u] != chains[v]) {
			if (dep[chains[u]] < dep[chains[v]]) {
				v = p[chains[v]];
			} else {
				u = p[chains[u]];
			}
		}
		return (dep[u] < dep[v] ? u : v);
	};
	
	std::function<int(int,int)> dis = [&](int u, int v) -> int {
		return dep[u] + dep[v] - dep[lca(u, v)] * 2;
	};
	
	while (q--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		a--; b--; c--;
		
		int ans = 0, mi = n;
		int x;
		x = dis(a, b);
		ans += x, mi = std::min(mi, x);
		x = dis(b, c);
		ans += x, mi = std::min(mi, x);
		x = dis(a, c);
		ans += x, mi = std::min(mi, x);
		
		std::cout << (ans / 2) - mi + 1 << '\n';
	}
	
	return 0;
}
