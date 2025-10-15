#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM ((int) 1e6)
#define MAXP 20
#define INF ((int) 1e9)
using namespace std;

int n, m, ans[MAXM + 5];
array<int, 4> E[MAXM + 5];

int root[MAXN + 5];
bool used[MAXM + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
int dep[MAXN + 5], pa[MAXN + 5][MAXP], f[MAXN + 5][MAXP], g[MAXN + 5][MAXP];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void dfs(int sn, int fa, int d) {
    dep[sn] = d;
    pa[sn][0] = fa;
    for (int p = 1; p < MAXP; p++) {
        pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
        f[sn][p] = max(f[sn][p - 1], f[pa[sn][p - 1]][p - 1]);
    }

    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        f[fn][0] = v[sn][i];
        dfs(fn, sn, d + 1);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

int query(int x, int d) {
    int ret = 0;
    for (int p = MAXP - 1; p >= 0; p--) if (d >> p & 1) {
        ret = max(ret, f[x][p]);
        x = pa[x][p];
    }
    return ret;
}

void update(int x, int d, int val) {
    for (int p = MAXP - 1; p >= 0; p--) if (d >> p & 1) {
        g[x][p] = min(g[x][p], val);
        x = pa[x][p];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &E[i][1], &E[i][2], &E[i][0]);
        E[i][3] = i;
    }

    sort(E + 1, E + m + 1);
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= m; i++) {
        int x = E[i][1], y = E[i][2];
        int rx = findroot(x), ry = findroot(y);
        if (rx == ry) continue;

        e[x].push_back(y); v[x].push_back(E[i][0]);
        e[y].push_back(x); v[y].push_back(E[i][0]);
        root[rx] = ry;
        used[E[i][3]] = true;
    }

    dfs(1, 0, 1);
    for (int p = 0; p < MAXP; p++) for (int i = 1; i <= n; i++) g[i][p] = INF;
    for (int i = 1; i <= m; i++) {
        int x = E[i][1], y = E[i][2], idx = E[i][3];
        if (used[idx]) continue;
        int a = lca(x, y);
        update(x, dep[x] - dep[a], E[i][0]);
        update(y, dep[y] - dep[a], E[i][0]);
        ans[idx] = max(query(x, dep[x] - dep[a]), query(y, dep[y] - dep[a]));
    }

    for (int p = MAXP - 1; p > 0; p--) for (int i = 1; i <= n; i++) {
        g[i][p - 1] = min(g[i][p - 1], g[i][p]);
        g[pa[i][p - 1]][p - 1] = min(g[pa[i][p - 1]][p - 1], g[i][p]);
    }
    for (int i = 1; i <= m; i++) {
        int x = E[i][1], y = E[i][2], idx = E[i][3];
        if (!used[idx]) continue;
        if (dep[x] < dep[y]) swap(x, y);
        ans[idx] = g[x][0];
    }

    printf("%d\n", ans[1]);
    return 0;
}
