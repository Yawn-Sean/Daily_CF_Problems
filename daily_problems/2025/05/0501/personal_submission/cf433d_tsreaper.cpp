#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, q, MAP[MAXN + 5][MAXN + 5];

int U[MAXN + 5][MAXN + 5], D[MAXN + 5][MAXN + 5], L[MAXN + 5][MAXN + 5], R[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &MAP[i][j]);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (MAP[i][j] == 0) U[i][j] = L[i][j] = 0;
        else U[i][j] = U[i - 1][j] + 1, L[i][j] = L[i][j - 1] + 1;
    }
    for (int i = n; i > 0; i--) for (int j = m; j > 0; j--) {
        if (MAP[i][j] == 0) D[i][j] = R[i][j] = 0;
        else D[i][j] = D[i + 1][j] + 1, R[i][j] = R[i][j + 1] + 1;
    }

    while (q--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            MAP[x][y] ^= 1;
            for (int i = 1; i <= n; i++) {
                if (MAP[i][y] == 0) U[i][y] = 0;
                else U[i][y] = U[i - 1][y] + 1;
            }
            for (int i = n; i > 0; i--) {
                if (MAP[i][y] == 0) D[i][y] = 0;
                else D[i][y] = D[i + 1][y] + 1;
            }
            for (int j = 1; j <= m; j++) {
                if (MAP[x][j] == 0) L[x][j] = 0;
                else L[x][j] = L[x][j - 1] + 1;
            }
            for (int j = m; j > 0; j--) {
                if (MAP[x][j] == 0) R[x][j] = 0;
                else R[x][j] = R[x][j + 1] + 1;
            }
        } else {
            int ans = 0;
            for (int j = y, u = n, d = n; j <= m; j++) {
                u = min(u, U[x][j]); d = min(d, D[x][j]);
                if (u == 0 || d == 0) break;
                ans = max(ans, (j - y + 1) * (u + d - 1));
            }
            for (int j = y, u = n, d = n; j > 0; j--) {
                u = min(u, U[x][j]); d = min(d, D[x][j]);
                if (u == 0 || d == 0) break;
                ans = max(ans, (y - j + 1) * (u + d - 1));
            }
            for (int i = x, l = m, r = m; i <= n; i++) {
                l = min(l, L[i][y]); r = min(r, R[i][y]);
                if (l == 0 || r == 0) break;
                ans = max(ans, (i - x + 1) * (l + r - 1));
            }
            for (int i = x, l = m, r = m; i > 0; i--) {
                l = min(l, L[i][y]); r = min(r, R[i][y]);
                if (l == 0 || r == 0) break;
                ans = max(ans, (x - i + 1) * (l + r - 1));
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
