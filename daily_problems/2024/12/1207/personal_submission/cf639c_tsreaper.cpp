#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;

int n, K, A[MAXN + 5];

int m, ans;
long long f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);

    m = -1;
    for (int i = 0; i <= n; i++) {
        scanf("%d", &A[i]);
        if (m < 0) {
            f[i] = (i > 0 ? f[i - 1] : 0) / 2 + A[i];
            if (f[i] & 1) m = i;
        }
    }
    if (m < 0) m = n;

    for (int i = n; i >= 0; i--) {
        if (i <= m) {
            long long rem = g[i + 1] * 2;
            rem += (i > 0 ? f[i - 1] : 0) / 2;
            if (abs(rem) <= K) {
                if (i < n) ans++;
                else if (rem != 0) ans++;
            }
        }
        g[i] = g[i + 1] * 2 + A[i];
        if (g[i] > INF) g[i] = INF;
        if (g[i] < -INF) g[i] = -INF;
    }
    printf("%d\n", ans);
    return 0;
}
