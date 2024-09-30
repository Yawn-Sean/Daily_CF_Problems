#include <bits/stdc++.h>
#define MAXN 500
#define MAXM 500
#define INF ((int) 1e9)
using namespace std;

int n, m, K, ans;
char A[MAXN + 10][MAXM + 10];

int B[MAXN + 10][MAXM + 10], f[MAXN + 10][MAXM + 10], g[MAXM + 10];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%s", A[i] + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) g[j] = g[j - 1] + A[i][j] - '0';
        for (int j = 0; j <= m; j++) B[i][j] = INF;
        for (int l = 1; l <= m; l++) for (int r = l - 1; r <= m; r++) {
            int t = g[m] - (g[r] - g[l - 1]);
            B[i][t] = min(B[i][t], r - l + 1);
        }
    }

    for (int i = 0; i <= n; i++) for (int j = 0; j <= K; j++) f[i][j] = INF;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= K; j++) for (int k = 0; k <= j && k <= m; k++)
        f[i][j] = min(f[i][j], f[i - 1][j - k] + B[i][k]);

    ans = INF;
    for (int j = 0; j <= K; j++) ans = min(ans, f[n][j]);
    printf("%d\n", ans);
    return 0;
}
