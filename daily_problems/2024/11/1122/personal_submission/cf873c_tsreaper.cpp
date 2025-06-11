#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m, K, ans1, ans2, A[MAXN + 5][MAXN + 5];

int f[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        scanf("%d", &A[i][j]);
        f[i][j] = f[i - 1][j] + A[i][j];
    }

    for (int j = 1; j <= m; j++) {
        int x = 0, y = 0, z = 0;
        for (int i = 1; i <= n; i++) if (A[i][j] == 1) {
            int len = min(K, n - i + 1);
            int v = f[i + len - 1][j] - f[i - 1][j];
            if (v > x) x = v, y = z;
            z++;
        }
        ans1 += x; ans2 += y;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
