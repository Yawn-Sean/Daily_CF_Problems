#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;

int n, X, Y, A[MAXN + 5];
long long ans;

long long f[MAXN + 5], g[MAXN + 5];

void solve() {
    scanf("%d%d%d", &n, &X, &Y);
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        sm += A[i];
    }

    f[0] = INF;
    for (int i = 1; i <= n; i++) f[i] = min(f[i - 1], A[i] - ((long long) A[i] & Y));
    g[n + 1] = INF;
    for (int i = n; i > 0; i--) g[i] = min(g[i + 1], A[i] - ((long long) A[i] & Y));

    ans = INF;
    for (int i = 1; i <= n; i++) {
        int v = A[i] | X;
        long long t = sm - A[i] + v;
        long long det = min(f[i - 1], g[i + 1]);
        det = min(det, v - ((long long) v & Y));
        ans = min(ans, t - det);
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
