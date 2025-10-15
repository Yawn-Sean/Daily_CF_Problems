#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 50
#define INF ((int) 1e9)
using namespace std;

int n, m;
char s[MAXN + 5];

int f[MAXN + 5][MAXM + 5][2], g[MAXN + 5][MAXM + 5][2];

int main() {
    scanf("%s%d", s + 1, &m); n = strlen(s + 1);
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k < 2; k++)
        f[i][j][k] = -INF, g[i][j][k] = INF;
    f[0][0][0] = g[0][0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k < 2; k++) {
        if (s[i] == 'F') {
            f[i][j][k] = f[i - 1][j][k] + (k ? -1 : 1);
            g[i][j][k] = g[i - 1][j][k] + (k ? -1 : 1);
            if (j > 0) {
                f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k ^ 1]);
                g[i][j][k] = min(g[i][j][k], g[i - 1][j - 1][k ^ 1]);
            }
        } else {
            f[i][j][k] = f[i - 1][j][k ^ 1];
            g[i][j][k] = g[i - 1][j][k ^ 1];
            if (j > 0) {
                f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + (k ? -1 : 1));
                g[i][j][k] = min(g[i][j][k], g[i - 1][j - 1][k] + (k ? -1 : 1));
            }
        }
    }
    
    int ans = 0;
    for (int j = m; j >= 0; j -= 2) for (int k = 0; k < 2; k++) ans = max({ans, f[n][j][k], -g[n][j][k]});
    printf("%d\n", ans);
    return 0;
}
