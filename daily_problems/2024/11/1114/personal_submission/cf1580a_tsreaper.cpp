#include <bits/stdc++.h>
#define MAXN 400
using namespace std;

int n, m, ans;
char MAP[MAXN + 5][MAXN + 5];

int f[MAXN + 5][MAXN + 5];

int calc(int u, int d, int j) {
    int ret = (d - 1 - u) - (f[d - 1][j] - f[u][j]);
    for (int jj = 1; jj <= 2; jj++) {
        ret += f[d - 1][j + jj] - f[u][j + jj];
        if (MAP[u][j + jj] == '0') ret++;
        if (MAP[d][j + jj] == '0') ret++;
    }
    return ret;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", MAP[i] + 1);
        for (int j = 1; j <= m; j++) f[i][j] = f[i - 1][j] + (MAP[i][j] - '0');
    }

    ans = n * m;
    for (int u = 1; u <= n; u++) for (int d = u + 4; d <= n; d++) {
        int h = d - 1 - u;
        int mn = calc(u, d, 1), det = 0;
        for (int j = 4; j <= m; j++) {
            ans = min(ans, mn + det + h - (f[d - 1][j] - f[u][j]));
            det += f[d - 1][j] - f[u][j];
            if (MAP[u][j] == '0') det++;
            if (MAP[d][j] == '0') det++;
            mn = min(mn, calc(u, d, j - 2) - det);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
