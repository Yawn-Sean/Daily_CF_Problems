#include <bits/stdc++.h>
using namespace std;

struct DSU {
	std::vector<int>p, siz;

	explicit DSU(size_t n) : p(n + 1), siz(n + 1, 1) {
		std::iota(p.begin(), p.end(), 0);
	}

	int find(int x) {
		if (p[x] != x) p[x] = find(p[x]);
		return p[x];
	}

	bool same(int x, int y) {
		return find(p[x]) == find(p[y]);
	}

	int size(int x) {
		return siz[find(x)];
	}

	int merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return y;
		if (siz[x] > siz[y]) std::swap(x, y);
		siz[y] += siz[x];
		p[x] = y;
		return y;
	}
};

const int N = 200005, M = N << 1;
int n, m;
std::vector<std::pair<int, long long>> g[N];
long long dist[N];

struct Edge{
	int u, v, w;
};

void bfs(int xx) {
	std::queue<int> q;
	std::vector<int> vis(n + 1);
	std::memset(dist, 0x3f, sizeof dist);
	dist[xx] = 0;
	vis[xx] = 1;
	q.push(xx);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto &[y, w] : g[x]) {
			if (vis[y]) continue;
			vis[y] = 1;
			dist[y] = dist[x] + w;
			q.push(y);
		}
	}
}

int son[N], siz[N], fa[N], dep[N];
void dfs1(int x, int father) {
	fa[x] = father;
	dep[x] = dep[father] + 1;
	siz[x] = 1;
	for (auto &[y, w] : g[x]) {
		if (y == father) continue;
		dfs1(y, x);
		siz[x] += siz[y];
		if (siz[y] > siz[son[x]]) son[x] = y;
	}
}

int id[N], idn, top[N], rnk[N];
void dfs2(int x, int father) {
	top[x] = father;
	id[x] = ++idn;
	rnk[idn] = x;
	if (son[x] == 0) return;
	dfs2(son[x], father);
	for (auto &[y, w] : g[x]) {
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

long long get_dist(int x, int y) {
	return dist[x] + dist[y] - 2 * dist[lca(x, y)];
}

bool sol() {
	std::cin >> n >> m;
	std::vector<Edge> edge(m);
	for (auto &[u, v, w] : edge) std::cin >> u >> v >> w;

	std::sort(edge.begin(), edge.end(),[&](auto &e1, auto &e2) {return e1.w < e2.w;});

	DSU dsu(n);
	for (auto &[u, v, w] : edge) {
		if (!dsu.same(u, v)) {
			dsu.merge(u, v);
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	if (dsu.size(1) != n) return 0;

	bfs(1);
	dfs1(1, 0);
	dfs2(1, 1);

	for (auto &[u, v, w] : edge) {
		if (w < get_dist(u, v)) return 0;
	}
	return 1;
}

void soviet() {
	if (sol()) std::cout << "YES";
	else std::cout << "NO";
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}