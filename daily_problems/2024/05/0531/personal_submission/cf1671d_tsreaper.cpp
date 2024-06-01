#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K, A[MAXN + 10];
int f[MAXN + 10], g[MAXN + 10];

void solve() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    long long sm = 0;
    for (int i = 2; i <= n; i++) sm += abs(A[i] - A[i - 1]);

    f[1] = abs(A[1] - 1);
    for (int i = 2; i <= n; i++) {
        int val = min(A[i], A[i - 1]) - 1;
        f[i] = min(f[i - 1], max(2 * val, 0));
    }
    g[n] = abs(A[n] - K);
    for (int i = n - 1; i > 0; i--) {
        int val = K - max(A[i], A[i + 1]);
        g[i] = min(g[i + 1], max(2 * val, 0));
    }
    int mn = 1e9;
    for (int i = 1; i <= n; i++) mn = min(mn, f[i] + g[i]);

    f[1] = abs(A[1] - K);
    for (int i = 2; i <= n; i++) {
        int val = K - max(A[i], A[i - 1]);
        f[i] = min(f[i - 1], max(2 * val, 0));
    }
    g[n] = abs(A[n] - 1);
    for (int i = n - 1; i > 0; i--) {
        int val = min(A[i], A[i + 1]) - 1;
        g[i] = min(g[i + 1], max(2 * val, 0));
    }
    for (int i = 1; i <= n; i++) mn = min(mn, f[i] + g[i]);

    mn = min({mn, K - 1 + abs(A[1] - 1), K - 1 + abs(A[1] - K)});
    for (int i = 2; i <= n; i++)
        mn = min({
            mn,
            K - 1 + abs(A[i] - 1) + abs(A[i - 1] - K) - abs(A[i] - A[i - 1]),
            K - 1 + abs(A[i] - K) + abs(A[i - 1] - 1) - abs(A[i] - A[i - 1])
        });
    mn = min({mn, K - 1 + abs(A[n] - 1), K - 1 + abs(A[n] - K)});

    printf("%lld\n", sm + mn);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
