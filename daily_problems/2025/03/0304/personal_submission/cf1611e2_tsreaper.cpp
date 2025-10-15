#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 20
using namespace std;

int n, K, A[MAXN + 5];

vector<int> e[MAXN + 5];
int pa[MAXN + 5][MAXP], dep[MAXN + 5];
bool flag[MAXN + 5];

void dfs(int sn, int fa, int d) {
    pa[sn][0] = fa;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
    dep[sn] = d;

    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1);
}

int calc(int sn, int d) {
    for (int p = MAXP - 1; p >= 0; p--) if (d >> p & 1) sn = pa[sn][p];
    return sn;
}

int dfs2(int sn, int fa) {
    if (flag[sn]) return 1;
    if (sn != 1 && e[sn].size() == 1) return -1;
    
    int ret = 0;
    for (int fn : e[sn]) if (fn != fa) {
        int tmp = dfs2(fn, sn);
        if (tmp == -1) return -1;
        ret += tmp;
    }
    return ret;
}

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= K; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    dfs(1, 0, 1);
    memset(flag, 0, sizeof(bool) * (n + 3));
    for (int i = 1; i <= K; i++) {
        int x = calc(A[i], (dep[A[i]] - 1) / 2);
        flag[x] = true;
    }
    printf("%d\n", dfs2(1, 0));
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
