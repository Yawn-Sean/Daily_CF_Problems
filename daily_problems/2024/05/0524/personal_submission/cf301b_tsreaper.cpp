#include <bits/stdc++.h>
#define INF ((long long) 1e18)
#define MAXN 100
using namespace std;

int n, D, A[MAXN + 10], X[MAXN + 10], Y[MAXN + 10];

long long g[MAXN + 10][MAXN + 10];

int main() {
    scanf("%d%d", &n, &D);
    for (int i = 2; i < n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (i == j) g[i][i] = 0;
        else g[i][j] = 1LL * D * (abs(X[i] - X[j]) + abs(Y[i] - Y[j])) - A[j];
    }

    for (int k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    printf("%lld\n", g[1][n]);
    return 0;
}
