#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q;

vector<int> e[MAXN + 10], v[MAXN + 10];
vector<int> E[MAXN * 2 + 10];
int f[MAXN * 2 + 10];

void conn(int x, int y) {
    E[x].push_back(y); E[y].push_back(x);
}

void gao(int x, int y, int z) {
    if (z == 0) conn(x, y), conn(x + n, y + n);
    else conn(x, y + n), conn(x + n, y);
}

void dfs1(int sn, int fa, int from) {
    if (from >= 0) gao(sn, fa, __builtin_popcount(from) & 1);
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        dfs1(fn, sn, v[sn][i]);
    }
}

void bfs(int S, int X) {
    queue<int> q;
    q.push(S); f[S] = X;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : E[sn]) if (f[fn] < 0) q.push(fn), f[fn] = X;
    }
}

void dfs2(int sn, int fa, int from, int now) {
    if (f[sn] == now) { if (from < 0) from = 0; }
    else { if (from < 0) from = 1; }
    if (fa > 0) printf("%d %d %d\n", fa, sn, from);
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        dfs2(fn, sn, v[sn][i], now ^ (__builtin_popcount(from) & 1));
    }
}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    for (int i = 1; i <= n * 2; i++) E[i].clear();
    for (int i = 1; i <= q; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        gao(x, y, z);
    }
    dfs1(1, 0, -1);

    memset(f, -1, sizeof(int) * (n * 2 + 3));
    for (int i = 1; i <= n; i++) if (f[i] < 0) {
        bfs(i, 0);
        if (f[i + n] == 0) { printf("NO\n"); return; }
        bfs(i + n, 1);
    }

    printf("YES\n");
    dfs2(1, 0, -1, 0);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
