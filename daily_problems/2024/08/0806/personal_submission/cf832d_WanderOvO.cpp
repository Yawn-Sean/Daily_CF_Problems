/*
对于每种询问，枚举哪个作为 f
假设确定了 s, f, t，如何计算重合的点数？
对于 s 到 f 的路径，每个点权值 + 1，对于 t 到 f 的路径，求权值和，和就是重合点数
*/

int main() {
    #ifdef LOCAL_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
	scanf("%d%d", &n, &T);
    r = 1;
	for (int i = 1; i <= n; i++) a[i] = 0;
	for (int i = 2; i <= n; i++) {
		int u = i, v;
		scanf("%d", &v);
		addedge(u, v, (i << 1) - 1); addedge(v, u, i << 1);
	}
	treelist::dfs1(r); treelist::dfs2(r);
	for (int i = 1; i <= n; i++) treelist::update(i, i, a[i]);
	while (T--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
        int res = 0;
        treelist::update(a, b, 1);
        res = max(res, treelist::query(a, c));
        res = max(res, treelist::query(b, c));
        treelist::update(a, b, -1);
        treelist::update(a, c, 1);
        res = max(res, treelist::query(b, c));
        treelist::update(a, c, -1);
        printf("%d\n", res);
	}
	return 0;
}
