#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
struct Tree {
	int n;
	std::vector<std::vector<int>> ver, val;
	std::vector<int> lg, dep;
	Tree(int n) {
		this->n = n;
		ver.resize(n + 1);
		val.resize(n + 1, std::vector<int>(30));
		lg.resize(n + 1);
		dep.resize(n + 1);
		for (int i = 1; i <= n; i++) { //预处理 log
			lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
		}
	}
	void add(int x, int y) { // 建立双向边
		ver[x].push_back(y);
		ver[y].push_back(x);
	}
	void dfs(int x, int fa) {
		val[x][0] = fa; // 储存 x 的父节点
		dep[x] = dep[fa] + 1;
		for (int i = 1; i <= lg[dep[x]]; i++) {
			val[x][i] = val[val[x][i - 1]][i - 1];
		}
		for (auto y : ver[x]) {
			if (y == fa) continue;
			dfs(y, x);
		}
	}
	int lca(int x, int y) {
		if (dep[x] < dep[y]) std::swap(x, y);
		while (dep[x] > dep[y]) {
			x = val[x][lg[dep[x] - dep[y]] - 1];
		}
		if (x == y) return x;
		for (int k = lg[dep[x]] - 1; k >= 0; k--) {
			if (val[x][k] == val[y][k]) continue;
			x = val[x][k];
			y = val[y][k];
		}
		return val[x][0];
	}
	int clac(int x, int y) { // 倍增查询两点间距离
		return dep[x] + dep[y] - 2 * dep[lca(x, y)];
	}
	void work(int root = 1) { // 在此初始化
		dfs(root, 0);
	}
};
void solve() {
	int n;
	std::cin >> n;
	std::vector<std::pair<i64, i64>> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	Tree tree(n);
	std::vector<int> st;
	st.push_back(n - 1);
	auto check = [&](int i, int j, int k)->bool{
		i64 va = (a[j].second - a[i].second) * (a[k].first - a[i].first);
		i64 vb = (a[k].second - a[i].second) * (a[j].first - a[i].first);
		return va > vb;
	};
	for (int i = n - 2; i >= 0; i--) {
		while (st.size() >= 2 && check(i, st[st.size() - 2], st.back())) {
			st.pop_back();
		}
		// std::cout << st.back() << " " << i << endl;
		tree.add(st.back() + 1, i + 1);
		st.push_back(i);
	}
	tree.work(n);
	int q; std::cin >> q;
	while (q--) {
		int u, v;
		std::cin >> u >> v;
		std::cout << tree.lca(u, v) << " ";
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
