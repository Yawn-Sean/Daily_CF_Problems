#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[MAXN + 5], B[MAXN + 5];
long long ans;

long long f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
    sort(A + 1, A + n + 1, greater<int>());
    sort(B + 1, B + m + 1, greater<int>());
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + A[i];
    for (int i = 1; i <= m; i++) g[i] = g[i - 1] + B[i];

    ans = f[n] + g[m];
    for (int i = 1; i <= n; i++) {
        long long v = (f[n] - f[i]) + g[m] * i;
        if (v >= ans) break;
        ans = v;
    }
    for (int i = 1; i <= m; i++) {
        long long v = (g[m] - g[i]) + f[n] * i;
        if (v >= ans) break;
        ans = v;
    }
    printf("%lld\n", ans);
    return 0;
}
