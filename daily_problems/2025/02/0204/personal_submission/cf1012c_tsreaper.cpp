#include <bits/stdc++.h>
#define MAXN 5000
#define INF ((long long) 1e18)
using namespace std;

int n, A[MAXN + 5];

long long f[2][MAXN + 5][2][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int j = 0; j <= n; j++) for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++) f[1][j][k][l] = INF;
    f[1][0][0][0] = f[1][1][1][0] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n; j++) for (int k = 0; k < 2; k++) for (int l = 0; l < 2; l++) f[i & 1][j][k][l] = INF;
        for (int j = 0; j <= (i + 1) / 2; j++) {
            f[i & 1][j][0][0] = min(f[i & 1 ^ 1][j][0][0], f[i & 1 ^ 1][j][0][1]);
            int x = A[i] - min(A[i], A[i - 1] - 1);
            f[i & 1][j][0][1] = f[i & 1 ^ 1][j][1][0] + x;
            if (j > 0) {
                int y = A[i - 1] - min(A[i - 1], A[i] - 1);
                int z = min(A[i - 1], A[i - 2] - 1);
                z -= min(z, A[i] - 1);
                f[i & 1][j][1][0] = min(f[i & 1 ^ 1][j - 1][0][0] + y, f[i & 1 ^ 1][j - 1][0][1] + z);
            }
        }
    }

    int m = (n + 1) / 2;
    for (int i = 1; i <= m; i++) printf("%lld%c", min({f[n & 1][i][0][0], f[n & 1][i][0][1], f[n & 1][i][1][0]}), "\n "[i < m]);
    return 0;
}
