#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 20
using namespace std;

int n, q;

vector<int> e[MAXN + 5];
int pa[MAXN + 5][MAXP], dep[MAXN + 5];

int now, ans[MAXN + 5];
vector<int> vec[MAXN + 5];

int root[MAXN + 5], keys[MAXN + 5][2];
bool flag[MAXN + 5];

void dfs(int sn, int fa, int d) {
    pa[sn][0] = fa;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
    dep[sn] = d;
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

int dis(int x, int y) {
    int a = lca(x, y);
    return dep[x] - dep[a] + dep[y] - dep[a];
}

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void conn(int x, int y) {
    x = findroot(x); y = findroot(y);
    assert(x != y);
    if (dep[x] < dep[y]) swap(x, y);
    vector<int> tmp = {keys[x][0], keys[x][1], keys[y][0], keys[y][1]};

    int a, b, len = -1;
    for (int i = 0; i < tmp.size(); i++) for (int j = i + 1; j < tmp.size(); j++) {
        int d = dis(tmp[i], tmp[j]);
        if (d > len) a = tmp[i], b = tmp[j], len = d;
    }

    root[x] = y;
    keys[y][0] = a; keys[y][1] = b;
    now = max(now, len + 1);
}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0, 1);

    now = 0;
    for (int i = 1; i <= n; i++) flag[i] = false;
    for (int i = 1; i <= q; i++) {
        int x, y; scanf("%d%d", &x, &y);
        int a = lca(x, y);

        vec[i].clear();
        for (int sn : vector<int>{x, y}) {
            while (dep[sn] >= dep[a]) {
                if (flag[sn]) { sn = pa[findroot(sn)][0]; continue; }
                vec[i].push_back(sn);
                root[sn] = keys[sn][0] = keys[sn][1] = sn;
                flag[sn] = true;
                for (int fn : e[sn]) if (flag[fn]) conn(sn, fn);
            }
        }
        ans[i] = now;
    }

    now = 0;
    for (int sn = 1; sn <= n; sn++) if (!flag[sn]) {
        root[sn] = keys[sn][0] = keys[sn][1] = sn;
        for (int fn : e[sn]) if (fn < sn && !flag[fn]) conn(sn, fn);
    }
    ans[q] = max(ans[q], now);
    for (int i = q - 1; i > 0; i--) {
        for (int sn : vec[i + 1]) {
            root[sn] = keys[sn][0] = keys[sn][1] = sn;
            flag[sn] = false;
            for (int fn : e[sn]) if (!flag[fn]) conn(sn, fn);
        }
        ans[i] = max(ans[i], now);
    }

    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
