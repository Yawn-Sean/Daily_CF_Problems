#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n;

vector<int> e[MAXN + 5];
bool vis[2][MAXN + 5];

int query(char c, int x) {
    printf("%c %d\n", c, x);
    fflush(stdout);
    int y; scanf("%d", &y);
    return y;
}

void dfs(int sn, int fa) {
    if (vis[0][sn]) {
        int t = query('A', sn);
        if (vis[1][t]) printf("C %d\n", sn);
        else printf("C -1\n");
        return;
    }
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) e[i].clear();
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int k = 0; k < 2; k++) for (int i = 1; i <= n; i++) vis[k][i] = false;
    for (int k = 0; k < 2; k++) {
        int m; scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            int x; scanf("%d", &x);
            vis[k][x] = true;
        }
    }

    int X;
    for (int i = 1; i <= n; i++) if (vis[1][i]) { X = query('B', i); break; }
    if (vis[0][X]) printf("C %d\n", X);
    else dfs(X, 0);
    fflush(stdout);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
