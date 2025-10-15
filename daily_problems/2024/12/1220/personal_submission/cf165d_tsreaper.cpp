#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 20
using namespace std;

int n, A[MAXN + 5][2];

vector<int> e[MAXN + 5];
int clk, bgn[MAXN + 5], fin[MAXN + 5], dep[MAXN + 5], pa[MAXN + 5][MAXP];
int tree[MAXN + 5];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

void dfs(int sn, int fa, int d) {
    bgn[sn] = ++clk;
    dep[sn] = d;
    pa[sn][0] = fa;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1);
    fin[sn] = clk;
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &A[i][0], &A[i][1]);
        e[A[i][0]].push_back(A[i][1]); e[A[i][1]].push_back(A[i][0]);
    }
    dfs(1, 0, 1);

    int q; scanf("%d", &q);
    while (q--) {
        int op; scanf("%d", &op);
        if (op <= 2) {
            int x; scanf("%d", &x);
            if (dep[A[x][0]] > dep[A[x][1]]) x = A[x][0];
            else x = A[x][1];
            add(bgn[x], op == 1 ? -1 : 1);
            if (fin[x] + 1 <= n) add(fin[x] + 1, op == 1 ? 1 : -1);
        } else {
            int x, y; scanf("%d%d", &x, &y);
            int a = lca(x, y);
            int dis = (dep[x] - dep[a]) + (dep[y] - dep[a]);
            if ((query(bgn[x]) - query(bgn[a])) + (query(bgn[y]) - query(bgn[a]))) printf("-1\n");
            else printf("%d\n", dis);
        }
    }
    return 0;
}
