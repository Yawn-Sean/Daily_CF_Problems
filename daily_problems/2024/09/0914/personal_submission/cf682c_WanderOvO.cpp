/*
其实就是保留最大的一个包含 1 的连通块，使得以 u 为根的子树中的所有点 v 满足 dist(u, v) <= a[v]
假设某个 v 不符合题意，则 v 所在的整个子树都得删了
对于每个 v，关心的是往上走的最远距离，假如 > a[v] 则以 v 为根的子树整个要删掉
考虑维护 u 往上走的最长距离，设为 d[u]
d[1] = 0
u 是 v 的父亲，则 d[v] = max(d[u] + w, 0)，判断 d[v] 是否 <= a[v]
*/

int T;
LL n, a[N], d[N];
LL h[N], e[M], ne[M], w[M], idx;
LL res = 0;

void add(LL a, LL b, LL c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dfs(int u, int fa) {
    res++;
    for (int i = h[u]; i >= 0; i = ne[i]) {
        int v = e[i];
        if (v != fa) {
            d[v] = max(d[u] + w[i], 0LL);
            if (d[v] <= a[v]) {
                dfs(v, u);
            }
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(h, -1, sizeof h);
    for (int i = 2; i <= n; i++) {
        LL p, c;
        cin >> p >> c;
        add(i, p, c);
        add(p, i, c);
    }
    d[1] = 0;
    dfs(1, 0);
    cout << n - res << "\n";
}                                                                                                                  
