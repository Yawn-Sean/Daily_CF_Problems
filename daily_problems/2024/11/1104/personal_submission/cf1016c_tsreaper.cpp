#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, A[2][MAXN + 10];
long long ans;

long long f[2][MAXN + 10], g[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) for (int j = 1; j <= n; j++) scanf("%d", &A[i][j]);

    for (int j = n; j > 0; j--) {
        long long det = (n - j) * 2 + 1;
        f[0][j] = f[0][j + 1] + g[j + 1] + det * A[1][j];
        f[1][j] = f[1][j + 1] + g[j + 1] + det * A[0][j];
        g[j] = g[j + 1] + A[0][j] + A[1][j];
    }

    ans = f[0][1];
    long long sm = 0;
    for (int j = 1, s = 0; j <= n; j++) {
        if (j & 1) {
            sm += 1LL * s * A[0][j];
            s++;
            sm += 1LL * s * A[1][j];
            s++;
            ans = max(ans, sm + f[1][j + 1] + s * g[j + 1]);
        } else {
            sm += 1LL * s * A[1][j];
            s++;
            sm += 1LL * s * A[0][j];
            s++;
            ans = max(ans, sm + f[0][j + 1] + s * g[j + 1]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
