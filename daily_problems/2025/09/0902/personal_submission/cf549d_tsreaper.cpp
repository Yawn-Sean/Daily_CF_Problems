#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m, ans;
char MAP[MAXN + 5][MAXN + 5];

long long f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    ans = 1;
    if (MAP[n][m] == 'W') f[n][m] = g[n][m] = 1;
    else f[n][m] = g[n][m] = -1;
    for (int i = n; i > 0; i--) for (int j = m; j > 0; j--) if (i != n || j != m) {
        f[i][j] = f[i + 1][j] + (g[i][j] = g[i][j + 1]);
        int goal = (MAP[i][j] == 'W' ? 1 : -1);
        if (f[i][j] != goal) {
            ans++;
            long long det = goal - f[i][j];
            f[i][j] += det;
            g[i][j] += det;
        }
    }

    printf("%d\n", ans);
    return 0;
}
