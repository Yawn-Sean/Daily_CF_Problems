#include <bits/stdc++.h>
#define MAXN 100
#define INF 1e200
using namespace std;

int n;
double ans, A[MAXN + 5];

double f[2][MAXN * 2 + 5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) scanf("%lf", &A[i]);
    
    int MAGIC = n * n + 5;
    for (int i = 0; i <= n * 2; i++) f[0][i] = -INF;
    f[0][n] = 0;
    for (int i = 1; i <= MAGIC; i++) {
        for (int j = 0; j <= n * 2; j++) f[i & 1][j] = -INF;
        for (int j = 0; j <= n * 2; j++) for (int k = 0; k <= n; k++) {
            int jj = j - (n - k * 2);
            if (jj < 0 || jj > n * 2) continue;
            f[i & 1][j] = max(f[i & 1][j], f[i & 1 ^ 1][jj] + A[k]);
        }
        for (int j = n; j <= n * 2; j++) ans = max(ans, f[i & 1][j] / i);
    }
    printf("%.12f\n", ans);
    return 0;
}
