#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int a[N][21];
std::vector<int>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
std::vector<int> e[N];

int fa[N],son[N], dep[N], siz[N];
void dfs1(int x, int father) {
	siz[x] = 1;
	fa[x] = father;
	dep[x] = dep[father] + 1;
	for (auto &y : e[x]) {
		if (y == father) continue;
		for (int i = 0; i < 19; i++) {
			a[y][i] += a[x][i];
		}
		dfs1(y, x);
		siz[x] += siz[y];
		if (siz[y] > siz[son[x]]) son[x] = y;
	}
}

int top[N], id[N], rnk[N], idn, dn;
void dfs2(int x, int father) {
	top[x] = father;
	id[x] = ++idn;
	rnk[idn] = x;
	if (son[x] == 0) return;
	dfs2(son[x], father);
	for (auto &y : e[x]) {
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
	int n; std::cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; std::cin >> x;
		for (int j = 0; j < 19; j++) {
			while (x % primes[j] == 0) {
				a[i][j]++;
				x /= primes[j];
			}
		}
	}

	for (int i = 1; i < n; i++) {
		int u, v; std::cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	int q; std::cin >> q;
	while (q--) {
		int x, y; std::cin >> x >> y;
		int z = lca(x, y);
		bool flag = false;
		for (int j = 0; j < 19; j++) {
			int now = a[x][j] - a[z][j] + a[y][j] - a[fa[z]][j];
			flag |= now & 1;
		}
		if (flag) std::cout << 1 << '\n';
		else std::cout << 0 << '\n';
	}
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
