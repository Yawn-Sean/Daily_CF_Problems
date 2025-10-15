#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, m, A[MAXN + 5];
int f[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) f[i][i] = A[i];
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        f[x][y] = f[y][x] = A[x] & A[y];
    }

    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        f[i][j] |= f[i][k] & f[k][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d", f[i][j] ? 1 : 0);
        printf("\n");
    }
    return 0;
}
