/*
注意这个题是当且仅当相邻时，颜色不同，所以不相邻的颜色必须相同，相当于在同一个集合里面
不妨直接考虑补图，把没出现的边用并查集维护起来，最后每个集合应该用同一种颜色
然后用原图检查会不会冲突
*/

int n, m, k;
int w[M][M], c[M], fa[M];

int find(int x) {
    if (x == fa[x]) {
        return fa[x];
    }
    return fa[x] = find(fa[x]);
}

bool together(int x, int y) {
    return find(x) == find(y);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

void meibao() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        w[u][v] = 1;
        w[v][u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (w[i][j] == 0) {
                merge(i, j);
            }
        }
    }

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            c[i] = ++idx;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i != fa[i]) {
            c[i] = c[fa[i]];
        }
    }

    if (idx > k) {
        cout << "-1\n";
    } else {
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && w[i][j]) {
                    if (c[i] == c[j]) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) {
            for (int i = 1; i <= n; i++) {
                cout << c[i] << " ";
            }
        } else {
            cout << "-1\n";
        }
    }
} 
