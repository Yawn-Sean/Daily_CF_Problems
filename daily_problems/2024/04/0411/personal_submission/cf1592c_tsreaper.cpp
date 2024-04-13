#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, A[MAXN + 10];

vector<int> e[MAXN + 10];
int X, f[MAXN + 10];
bool ok;

int dfs1(int sn, int fa) {
    f[sn] = A[sn];
    for (int fn : e[sn]) if (fn != fa) f[sn] ^= dfs1(fn, sn);
    return f[sn];
}

bool dfs2(int sn, int fa, bool zero) {
    if (f[sn] == 0) zero = true;
    int cnt = 0;
    bool ret = false;
    for (int fn : e[sn]) if (fn != fa) {
        bool t = dfs2(fn, sn, zero);
        if (t) cnt++, ret = true;
    }
    if (f[sn] == X) {
        if (zero) ok = true;
        ret = true;
    }
    if (cnt >= 2) ok = true;
    return ret;
}

void solve() {
    scanf("%d%d", &n, &K);
    X = 0;
    for (int i = 1; i <= n; i++) e[i].clear();

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        X ^= A[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    if (X == 0) { printf("YES\n"); return; }
    if (K <= 2) { printf("NO\n"); return; }
    ok = false; dfs1(1, 0); dfs2(1, 0, false);
    if (ok) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
