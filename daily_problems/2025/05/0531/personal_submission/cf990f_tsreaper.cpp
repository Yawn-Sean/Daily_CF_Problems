#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 20
using namespace std;

int n, m, A[MAXN + 5];
long long ans[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
int vis[MAXN + 5], pa[MAXN + 5][MAXP], dep[MAXN + 5];

vector<int> pos, neg;
long long B[MAXN + 5];

void dfs1(int sn, int fa, int d) {
    vis[sn] = 1;
    pa[sn][0] = fa;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];    
    dep[sn] = d;

    if (A[sn] > 0) pos.push_back(sn);
    else if (A[sn] < 0) neg.push_back(sn);

    for (int fn : e[sn]) if (vis[fn] == 0) dfs1(fn, sn, d + 1);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

long long dfs2(int sn, int from) {
    vis[sn] = 2;
    long long sm = B[sn];
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (vis[fn] == 2) continue;
        sm += dfs2(fn, v[sn][i]);
    }
    if (from > 0) ans[from] = sm;
    else if (from < 0) ans[-from] = -sm;
    return sm;
}

void gao(int S) {
    pos.clear(); neg.clear();
    dfs1(S, 0, 1);
    long long sm = 0;
    for (int x : pos) sm += A[x];
    for (int x : neg) sm += A[x];
    if (sm != 0) { printf("Impossible\n"); exit(0); }

    while (!pos.empty()) {
        int x = pos.back(), y = neg.back();
        int a = lca(x, y);
        int t = min(A[x], -A[y]);
        B[x] += t; B[a] -= t;
        B[y] -= t; B[a] += t;
        A[x] -= t; A[y] += t;
        if (A[x] == 0) pos.pop_back();
        if (A[y] == 0) neg.pop_back();
    }
    dfs2(S, 0);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(i);
        e[y].push_back(x); v[y].push_back(-i);
    }

    for (int i = 1; i <= n; i++) if (vis[i] == 0) gao(i);
    printf("Possible\n");
    for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    return 0;
}
