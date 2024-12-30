#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, P, K, ans, A[MAXN + 10];
long long f[MAXN + 10], g[MAXN + 10];

void solve() {
    scanf("%d%d%d", &n, &P, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);

    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + A[i];
        g[i] = 0;
        if (i >= K) g[i] = g[i - K] + A[i];
    }

    ans = 0;
    for (int i = 1; i <= n; i++) {
        long long t;
        if (i < K) t = f[i];
        else t = g[i] + f[i % K];
        if (t <= P) ans = max(ans, i);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
