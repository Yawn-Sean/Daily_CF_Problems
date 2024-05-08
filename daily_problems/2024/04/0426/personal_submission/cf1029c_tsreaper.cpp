#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, A[MAXN + 10][2];
int f[MAXN + 10][2], g[MAXN + 10][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i][0], &A[i][1]);

    f[0][0] = -1e9; f[0][1] = 1e9;
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], A[i][0]);
        f[i][1] = min(f[i - 1][1], A[i][1]);
    }

    g[n + 1][0] = -1e9; g[n + 1][1] = 1e9;
    for (int i = n; i > 0; i--) {
        g[i][0] = max(g[i + 1][0], A[i][0]);
        g[i][1] = min(g[i + 1][1], A[i][1]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = max(f[i - 1][0], g[i + 1][0]);
        int r = min(f[i - 1][1], g[i + 1][1]);
        ans = max(ans, r - l);
    }
    printf("%d\n", ans);
    return 0;
}
