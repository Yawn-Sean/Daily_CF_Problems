#include <bits/stdc++.h>
#define MAXN 1000
#define MAXM 1000
#define INF ((long long) 1e18)
using namespace std;

int n, m, A[MAXN + 5][MAXM + 5];
long long ans;

long long f[4][MAXN + 5][MAXM + 5];

void update(long long &a, long long b) {
    a = max(a, b);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &A[i][j]);
    for (int k = 0; k < 4; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[k][i][j] = -INF;

    f[0][1][1] = A[1][1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (i < n) update(f[0][i + 1][j], f[0][i][j] + A[i + 1][j]);
        if (j < m) update(f[0][i][j + 1], f[0][i][j] + A[i][j + 1]);
    }

    f[1][n][m] = A[n][m];
    for (int i = n; i > 0; i--) for (int j = m; j > 0; j--) {
        if (i > 1) update(f[1][i - 1][j], f[1][i][j] + A[i - 1][j]);
        if (j > 1) update(f[1][i][j - 1], f[1][i][j] + A[i][j - 1]);
    }

    f[2][n][1] = A[n][1];
    for (int i = n; i > 0; i--) for (int j = 1; j <= m; j++) {
        if (i > 1) update(f[2][i - 1][j], f[2][i][j] + A[i - 1][j]);
        if (j < m) update(f[2][i][j + 1], f[2][i][j] + A[i][j + 1]);
    }

    f[3][1][m] = A[1][m];
    for (int i = 1; i <= n; i++) for (int j = m; j > 0; j--) {
        if (i < n) update(f[3][i + 1][j], f[3][i][j] + A[i + 1][j]);
        if (j > 1) update(f[3][i][j - 1], f[3][i][j] + A[i][j - 1]);
    }

    ans = -INF;
    for (int i = 2; i < n; i++) for (int j = 2; j < m; j++) {
        ans = max({
            ans,
            f[0][i - 1][j] + f[1][i + 1][j] + f[2][i][j - 1] + f[3][i][j + 1],
            f[0][i][j - 1] + f[1][i][j + 1] + f[2][i + 1][j] + f[3][i - 1][j],
        });
    }
    printf("%lld\n", ans);
    return 0;
}
