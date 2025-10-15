#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, OX[2], OY[2];
long long ans;

long long f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) scanf("%d%d", &OX[i], &OY[i]);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        f[i] = 1LL * (OX[0] - x) * (OX[0] - x) + 1LL * (OY[0] - y) * (OY[0] - y);
        g[i] = 1LL * (OX[1] - x) * (OX[1] - x) + 1LL * (OY[1] - y) * (OY[1] - y);
    }

    ans = 9e18;
    for (int i = 0; i <= n; i++) {
        long long mx = 0;
        for (int j = 1; j <= n; j++) if (f[j] > f[i]) mx = max(mx, g[j]);
        ans = min(ans, f[i] + mx);
    }
    printf("%lld\n", ans);
    return 0;
}
