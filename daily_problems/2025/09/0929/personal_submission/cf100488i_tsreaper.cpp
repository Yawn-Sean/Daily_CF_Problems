#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, K, ans[MAXN + 5];
bool g[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        g[x][y] = g[y][x] = true;
    }

    int c = 0;
    for (int i = 1; i <= n; i++) if (!ans[i]) {
        ans[i] = ++c;
        for (int j = 1; j <= n; j++) if (i != j && !g[i][j]) ans[j] = c;
    }
    if (c > K) { printf("-1\n"); return 0; }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) {
        if (g[i][j] && ans[i] == ans[j]) { printf("-1\n"); return 0; }
        if (!g[i][j] && ans[i] != ans[j]) { printf("-1\n"); return 0; }
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
