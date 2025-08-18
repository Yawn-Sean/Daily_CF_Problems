#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
long long ans;

vector<int> e[MAXN + 5];
int clk, dfn[MAXN + 5], low[MAXN + 5];

int tarjan(int sn, int fa) {
    int ret = 1;
    dfn[sn] = low[sn] = ++clk;
    for (int fn : e[sn]) {
        if (dfn[fn] == 0) {
            int sz = tarjan(fn, sn);
            ret += sz;
            low[sn] = min(low[sn], low[fn]);
            if (low[fn] > dfn[sn]) {
                long long t = 1LL * sz * (sz - 1) / 2;
                t += 1LL * (n - sz) * (n - sz - 1) / 2;
                ans = min(ans, t);
            }
        } else if (fn != fa) {
            low[sn] = min(low[sn], dfn[fn]);
        }
    }
    return ret;
}

void solve() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) e[i].clear();
    clk = 0;
    memset(dfn, 0, sizeof(int) * (n + 3));
    memset(low, 0, sizeof(int) * (n + 3));

    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    ans = 1LL * n * (n - 1) / 2;
    tarjan(1, 0);
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
