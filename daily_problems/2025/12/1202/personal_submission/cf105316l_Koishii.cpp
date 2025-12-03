#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Fenwick {
	int n;
	std::vector<T> t;

	explicit Fenwick(int _n = 0) : n(_n) {
		t.assign(_n + 1, T{});
	}

	void add(int i, const T& x) {
		while (i <= n) {
			t[i] += x;
			i += i & -i;
		}
	}

	T sum(int i) {
		T ans = 0;
		while (i) {
			ans += t[i];
			i -= i & -i;
		}
		return ans;
	}


	int kth(T k) {
		int x = 0;
		T ans = 0;
		for (int i = std::log2(n); i >= 0; i--) {
			int nx = x + (1 << i);
			if (nx <= n && ans + t[nx] < k) {
				x = nx;
				ans += t[x];
			}
		}
		return x + 1;
	}

	T sum(int l, int r) { return sum(r) - sum(l - 1); }
	T query(int i) { return sum(i); }
	T query(int l, int r) { return sum(l, r); }
};

const int N = 500005;
int a[N << 1];
std::vector<int> e[N];
int ls[N], rs[N], dn;

int siz[N], son[N], fa[N], dep[N];
void dfs1(int x, int father) {
	ls[x] = ++dn;
	siz[x] = 1;
	fa[x] = father;
	dep[x] = dep[father] + 1;
	for (int &y : e[x]) {
		if (y == father) continue;
		dfs1(y, x);
		siz[x] += siz[y];
		if (son[x] == -1 || siz[y] > siz[son[x]]) son[x] = y;
	}
	rs[x] = dn;
}

int id[N], idn, top[N], rnk[N];
void dfs2(int x, int father) {
	top[x] = father;
	id[x] = ++idn;
	rnk[idn] = x;
	if (son[x] == -1) return;
	dfs2(son[x], father);
	for (int &y : e[x]) {
		if (y == son[x] || y == fa[x]) continue;
		dfs2(y, y);
	}
}

int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] > dep[top[y]]) x = fa[top[x]];
		else y = fa[top[y]];
	}
	return dep[x] < dep[y] ? x : y;
}

void soviet() {
	int n, q; std::cin >> n >> q;
	idn = dn = 0;
	for (int i = 0; i <= n + 1; i++) {
		e[i].clear();
		siz[i] = fa[i] = dep[i] = id[i] = top[i] = rnk[i] = 0;
		son[i] = -1;
	}
	std::string s; std::cin >> s; s = ' ' + s;
	for (int i = 1; i <= n * 2; i++) {
		std::cin >> a[i];
	}

	std::vector<int> notes(2 * n + 1);
	std::vector<int> sk(1, 0);
	int pt = 1;
	for (int i = 1; i <= n * 2; i++) {
		if (s[i] == '(') {
			e[sk.back()].emplace_back(pt);
			sk.emplace_back(pt);
			notes[i] = pt++;
		}
		else sk.pop_back();
	}

	dfs1(0, n + 1);
	dfs2(0, 0);

	Fenwick<long long> t(n + 1);

	while (q--) {
		int op; std::cin >> op;
		if (op == 1) {
			int l1, r1, l2, r2, val; std::cin >> l1 >> r1 >> l2 >> r2 >> val;
			int u = notes[l1], v = notes[l2];
			int l = lca(u, v);
			t.add(ls[l], val);
		}
		else {
			int l, r; std::cin >> l >> r;
			int u = notes[l];
			std::cout << t.sum(ls[u], rs[u]) + a[l] << '\n';
		}
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
