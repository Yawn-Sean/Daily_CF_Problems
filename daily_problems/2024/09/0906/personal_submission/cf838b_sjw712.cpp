const int N = 200010, M = N * 2;
int h[N], ne[M], e[M], w[M], idx;
int w1[N], w2[N], p[N], dfn[N], sz[N], dist[N], id[N];
pii edge[M];
void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}
void dfs(int u, int fa){
	p[u] = fa, sz[u] = 1, dfn[++ idx] = u, id[u] = idx;
	for(int i = h[u]; ~i; i = ne[i]){
		int j = e[i];
		if(j == fa) continue;
		dist[j] = dist[u] + w[i];
		w2[j] = w[i];
		dfs(j, u);
		sz[u] += sz[j];
	}
}

struct Node{
	int l, r;
	int mn, add;
}tr[N * 4];
void pushup(int u){
	tr[u].mn = min(tr[u << 1].mn, tr[u << 1 | 1].mn);
}
void pushdown(int u){
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add){
        left.add += root.add, left.mn += root.add;
        right.add += root.add, right.mn += root.add;
        root.add = 0;
    }
}
void build(int u, int l, int r){
	if(l == r){
		tr[u] = {l, r, dist[dfn[l]] + w1[dfn[l]], 0};
		return;
	}
	tr[u] = {l, r};
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(int u, int l, int r, int v){
    if (tr[u].l >= l && tr[u].r <= r){
        tr[u].mn += v;
        tr[u].add += v;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, r, v);
    if (r > mid) modify(u << 1 | 1, l, r, v);
    pushup(u);
}
void modify(int u, int x, int v){
	if(tr[u].l == tr[u].r){
		tr[u].mn = v;
		return;
	}
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if(x <= mid) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);
	pushup(u);
}
int query_min(int u, int l, int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u].mn;
	int res = 1e18;
	int mid = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	if(l <= mid) res = min(res, query_min(u << 1, l, r));
	if(r > mid) res = min(res, query_min(u << 1 | 1, l, r));
	return res;
}
void solve(){
	int n, q;
	cin >> n >> q;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n - 1; i ++){
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = {a, b};
		add(a, b, c);
		add(b, a, c);
	}
	for(int i = 1; i <= n - 1; i ++){
		int a, b, c;
		cin >> a >> b >> c;
		edge[i + n - 1] = {a, b};
		w1[a] = c;
	}
	idx = 0;
	dfs(1, 0);
	build(1, 1, n);
	auto get = [&](int v)->int{
		return query_min(1, id[v], id[v]) - w1[v];
	};
	while(q --){
		int op;
		cin >> op;
		if(op == 1){
			int x, wt;
			cin >> x >> wt;
			if(x >= n){
				int u = edge[x].x;
				modify(1, id[u], wt + get(u));
				w1[u] = wt;
			}
			else{
				int u = edge[x].x, v = edge[x].y;
				if(p[v] == u) swap(u, v);
				int l = id[u], r = id[u] + sz[u] - 1;
				int delta = wt - w2[u];
				w2[u] = wt;
				modify(1, l, r, delta);
			}
		}
		else{
			int u, v;
			cin >> u >> v;
			if(u == v){
				cout << 0 << '\n';
				continue;
			}
			if(u == 1){
				cout << get(v) << "\n";
			}
			else{
				int ans = query_min(1, id[u], id[u] + sz[u] - 1) - get(u) + get(v);
				if(id[v] >= id[u] && id[v] <= id[u] + sz[u] - 1) ans = min(ans, get(u) + get(v) - 2 * get(u));
				cout << ans << '\n';
			}
		}
	}
}
