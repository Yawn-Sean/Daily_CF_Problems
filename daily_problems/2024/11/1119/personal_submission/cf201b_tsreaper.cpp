#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, R[MAXN + 5], C[MAXN + 5];
long long f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int x; scanf("%d", &x);
        R[i] += x; C[j] += x;
    }

    for (int i = 0; i <= n; i++) for (int t = 1; t <= n; t++) {
        int d = t * 4 - 2 - i * 4;
        f[i] += 1LL * d * d * R[t];
    }
    for (int j = 0; j <= m; j++) for (int t = 1; t <= m; t++) {
        int d = t * 4 - 2 - j * 4;
        g[j] += 1LL * d * d * C[t];
    }

    long long ans = 1e18;
    int ansI, ansJ;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) if (ans > f[i] + g[j]) {
        ans = f[i] + g[j];
        ansI = i; ansJ = j;
    }
    printf("%lld\n%d %d\n", ans, ansI, ansJ);
    return 0;
}
