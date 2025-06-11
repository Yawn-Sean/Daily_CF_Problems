
struct Circle {
    LL r, x, y, id;

    bool operator<(const Circle o) const {
        return r > o.r;
    }
};

int n, m, k;
Circle cs[N];
int fa[N][17];
int h[N], e[M], ne[M], idx;
int root;
int lg[N], d[N];
int new_id[N];

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> cs[i].x >> cs[i].y;
        cs[i].r = 0;
        cs[i].id = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> cs[n + i].r >> cs[n + i].x >> cs[n + i].y;
        cs[n + i].id = n + i;
    }
    cs[n + m + 1].r = INF;
    cs[n + m + 1].x = 0;
    cs[n + m + 1].y = 0;
    cs[n + m + 1].id = n + m + 1;

    memset(h, -1, sizeof h);
    idx = 0;
    root = n + m + 1;
    sort(cs + 1, cs + n + m + 2);
    for (int i = 1; i <= n + m + 1; i++) {
        if (cs[i].id <= n) {
            new_id[cs[i].id] = i;
        }
    }
    for (int i = 1; i <= n + m + 1; i++) {
        for (int j = i - 1; j > 0; j--) {
            if ( (cs[i].x - cs[j].x) * (cs[i].x - cs[j].x) + (cs[i].y - cs[j].y) * (cs[i].y - cs[j].y) < (cs[i].r - cs[j].r) * (cs[i].r - cs[j].r) ) {
                add(j, i);
                break;
            }
        }
    }
    for (int i = 2; i <= n + m + 1; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    d[1] = 1;
    dfs(1, -1);
    while (k--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << "0\n";
        } else {
            x = new_id[x];
            y = new_id[y];
            cout << d[x] + d[y] - d[lca(x, y)] * 2 - 2 << "\n";
        }
    }
}
