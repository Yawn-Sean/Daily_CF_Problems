#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 20
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m;

struct Edge {
    int fn, nxt;
    bool bridge;
};
vector<Edge> e;
int p[MAXN + 10];
int clk, dfn[MAXN + 10], low[MAXN + 10];

int N, bel[MAXN + 10], sz[MAXN + 10];
int dep[MAXN + 10], pa[MAXN + 10][MAXP], f[MAXN + 10][MAXP];
vector<int> E[MAXN + 10];

void adde(int sn, int fn) {
    int idx = e.size();
    e.push_back({fn, p[sn], false});
    p[sn] = idx;
}

void tarjan(int sn, int ban) {
    dfn[sn] = low[sn] = ++clk;
    for (int i = p[sn]; i >= 0; i = e[i].nxt) if (i != ban) {
        int fn = e[i].fn;
        if (!dfn[fn]) {
            tarjan(fn, i ^ 1);
            low[sn] = min(low[sn], low[fn]);
            if (low[fn] > dfn[sn]) e[i].bridge = e[i ^ 1].bridge = true;
        } else {
            low[sn] = min(low[sn], dfn[fn]);
        }
    }
}

void bfs(int S) {
    queue<int> q;
    q.push(S); bel[S] = ++N; sz[N] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = p[sn]; i >= 0; i = e[i].nxt) if (!e[i].bridge) {
            int fn = e[i].fn;
            if (bel[fn]) continue;
            q.push(fn);
            bel[fn] = N; sz[N]++;
        }
    }
}

int val(int sn) { return sz[sn] > 1 ? 1 : 0; }

void dfs(int sn, int fa, int d) {
    dep[sn] = d;
    pa[sn][0] = fa;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
    f[sn][0] = val(sn);
    for (int p = 1; p < MAXP; p++) f[sn][p] = f[sn][p - 1] + f[pa[sn][p - 1]][p - 1];
    for (int fn : E[sn]) if (fn != fa) dfs(fn, sn, d + 1);
}

int query(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    int ret = 0;
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) {
        ret += f[x][p];
        x = pa[x][p];
    }
    if (x == y) return ret + val(x);
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) {
        ret += f[x][p] + f[y][p];
        x = pa[x][p]; y = pa[y][p];
    }
    return ret + f[x][0] + f[y][0] + val(pa[x][0]);
}

long long P[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    memset(p, -1, sizeof(int) * (n + 3));
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        adde(x, y); adde(y, x);
    }

    tarjan(1, -1);
    for (int i = 1; i <= n; i++) if (!bel[i]) bfs(i);
    for (int i = 0; i < e.size(); i += 2) if (e[i].bridge) {
        int x = bel[e[i].fn], y = bel[e[i ^ 1].fn];
        E[x].push_back(y); E[y].push_back(x);
    }
    dfs(1, 0, 1);

    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;
    int q; scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%lld\n", P[query(bel[x], bel[y])]);
    }
    return 0;
}
