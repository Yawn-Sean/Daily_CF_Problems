const int N = 1e3+5;

int n, d, x, y;

struct Dsu {
	int fa[N], sz[N];
	void init(int x) {rep(i, 1, x) fa[i] = i, sz[i] = 1;}
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		int u = find(x), v = find(y);
		if(u == v) return 0;
		if(sz[u] < sz[v]) swap(u, v);
		fa[v] = u;
		sz[u] += sz[v];
		sz[v] = 0;
		return 1;
	}
}dsu;

int main() {
	scanf("%d%d", &n, &d);
	dsu.init(n);
	int cnt = 1;
	rep(i, 1, d) {
		scanf("%d%d", &x, &y);
		cnt += !dsu.merge(x, y);
		vector<int> cb;
		rep(j, 1, n) if(dsu.find(j) == j) cb.push_back(dsu.sz[j]);
		sort(cb.begin(), cb.end(), greater<int>());
		int sz = cb.size(), ans = 0;
		rep(j, 0, min(sz, cnt) - 1) ans += cb[j];
		printf("%d\n", ans-1);
	}
	return 0;
}
