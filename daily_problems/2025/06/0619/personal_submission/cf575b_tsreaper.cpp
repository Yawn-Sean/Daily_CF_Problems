#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 20
#define MAXQ ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
long long ans, P[MAXQ + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
int pa[MAXN + 5][MAXP], dep[MAXN + 5], A[MAXN + 5], B[MAXN + 5];

void dfs1(int sn, int fa, int d) {
    pa[sn][0] = fa; dep[sn] = d;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
    for (int fn : e[sn]) if (fn != fa) dfs1(fn, sn, d + 1);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

void dfs2(int sn, int fa, int val) {
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        dfs2(fn, sn, v[sn][i]);
        A[sn] += A[fn]; B[sn] += B[fn];
    }
    if (val == 1) ans = (ans + P[A[sn]] - 1 + MOD) % MOD;
    else if (val == -1) ans = (ans + P[B[sn]] - 1 + MOD) % MOD;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); e[y].push_back(x);
        if (z) {
            v[x].push_back(1); v[y].push_back(-1);
        } else {
            v[x].push_back(0); v[y].push_back(0);
        }
    }
    dfs1(1, 0, 1);

    int q; scanf("%d", &q);
    for (int i = 1, now = 1; i <= q; i++) {
        int x; scanf("%d", &x);
        int a = lca(now, x);
        A[now]++; A[a]--;
        B[x]++; B[a]--;
        now = x;
    }

    P[0] = 1;
    for (int i = 1; i <= q; i++) P[i] = P[i - 1] * 2 % MOD;
    dfs2(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}
