#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, q, QRY[MAXN + 5];
char s[MAXN + 5];

vector<int> e[MAXN + 5];
int X, Y, pa[MAXN + 5];
bool flag[MAXN + 5];

void dfs(int sn, int fa) {
    pa[sn] = fa;
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn);
}

void gao(int sn) {
    while (!flag[sn]) {
        flag[sn] = true;
        Y++;
        sn = pa[sn];
    }
}

long long calc(int x) {
    return 1LL * (x + 1) * x / 2;
}

void solve() {
    scanf("%d%d%s", &n, &q, s + 1);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int i = 1; i <= q; i++) scanf("%d", &QRY[i]);

    int rt = -1;
    for (int i = 1; i <= n; i++) if (s[i] == '0') rt = i;
    if (rt == -1) rt = QRY[1];

    dfs(rt, 0);
    for (int i = 1; i <= n; i++) flag[i] = false;
    X = Y = 1;
    flag[rt] = true; s[rt] = '0';
    for (int i = 1; i <= n; i++) if (i != rt && s[i] == '0') X++, gao(i);

    for (int i = 1; i <= q; i++) {
        int key = QRY[i];
        if (s[key] == '1') {
            s[key] = '0';
            X++;
            gao(key);
        }
        printf("%lld\n", calc(n - X) - calc(Y - X));
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
