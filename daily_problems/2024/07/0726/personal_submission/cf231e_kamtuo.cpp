/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-26 13:42 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 212345, MOD = 1000000007;

int n, m;
int p[N];
int ne[N], idx = 1, d[N], h[N];
int tot, to[N];
int fu[N], w[N];
int dfn[N], low[N], cnt;
int dep[N];
int fa[N][20];

struct E {
    int u, v;
    bool use;
} e[N];

void add(int u, int v) {
    ne[idx] = h[u];
    d[idx] = v;
    h[u] = idx ++;
}

// int dep[N];
int new_n;
int ne2[N], idx2 = 1, d2[N], h2[N];

void add2(int u, int v) {
    ne2[idx2] = h2[u];
    d2[idx2] = v;
    h2[u] = idx2 ++;
}

void tarjan(int now, int fa) {
    dfn[now] = low[now] = ++ cnt;
    for (int i = h[now]; i; i = ne[i]) {
        if (!dfn[d[i]]) {
            fu[d[i]] = now;
            tarjan(d[i], now);
            low[now] = min(low[now], low[d[i]]);
            if (dfn[now] < low[d[i]]) {
                // cout << now << ' ' << d[i] << endl;
                add2(now, d[i]);
            }
        } else if (d[i] != fa) {
            low[now] = min(low[now], dfn[d[i]]);
        }
    }
    for (int i = h[now]; i; i = ne[i]) {
        if (dfn[now] < dfn[d[i]] && fu[d[i]] != now) {
            ++ new_n;
            add2(now, new_n);
            w[now] ++;
            // cout << now << ' ' << new_n << endl;
            for (int k = d[i]; k != now; k = fu[k]) {
                // cout << new_n << ' ' << k << endl;
                // w[k] ++;
                add2(new_n, k);
            }
        }
    }
}

void dfs2(int now) {
    // cout << now << ' ' << w[now] << endl;
    for (int i = h2[now]; i; i = ne2[i]) {
        w[d2[i]] = (w[now] + w[d2[i]]);
        dep[d2[i]] = dep[now] + 1;
        fa[d2[i]][0] = now;
        for (int k = 1; k < 20; k ++) {
            fa[d2[i]][k] = fa[fa[d2[i]][k - 1]][k - 1];
        }
        dfs2(d2[i]);
    }

}

int lca(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    for (int i = 19; i >= 0; i --) {
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    }
    // cout << u << endl;
    if (u == v) return u;
    for (int i = 19; i >= 0; i --) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int two[N];

int main() {
    cin >> n >> m;
    two[0] = 1;
    for (int i = 1; i <= n; i ++) {
        two[i] = 1ll * two[i - 1] * 2ll % MOD;
    } 
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    new_n = n;
    tarjan(1, -1);
    dep[1] = 1;
    dfs2(1);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i ++) {
        int u, v;
        cin >> u >> v;
        int p = lca(u, v);
        int ans = w[u] - w[p] + w[v] - w[p] + w[p] - w[fa[p][0]];
        if (fa[p][0] > n || p > n) ans ++;
        // cout << w[u] << ' ' << w[p] << ' ' << w[v] << endl;
        // cout << w[fa[p][0]] << endl;
        cout << two[ans] << endl; 
    }
    return 0;
}

/*

*/
