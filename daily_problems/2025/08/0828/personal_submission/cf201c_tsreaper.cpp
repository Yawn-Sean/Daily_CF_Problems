#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;

long long f[MAXN + 5], g[MAXN + 5], h[MAXN + 5];

void gao() {
    for (int i = 2; i <= n; i++) {
        int t = A[i - 1] / 2 * 2;
        if (t > 0) f[i] = f[i - 1] + t;
        else f[i] = 0;
    }
    for (int i = n - 1; i > 0; i--) {
        int t = A[i] / 2 * 2;
        if (t > 0) g[i] = g[i + 1] + t;
        else g[i] = 0;
    }
    for (int i = n - 1; i > 0; i--) {
        h[i] = max(g[i], h[i + 1] + (A[i] - 1) / 2 * 2 + 1);
        ans = max(ans, f[i] + h[i]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) scanf("%d", &A[i]);

    gao();
    for (int i = 1, j = n - 1; i < j; i++, j--) swap(A[i], A[j]);
    gao();
    printf("%lld\n", ans);
    return 0;
}
