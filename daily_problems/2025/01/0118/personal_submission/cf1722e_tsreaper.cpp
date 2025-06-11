#include <bits/stdc++.h>
#define MAXA 1000
using namespace std;

long long f[MAXA + 5][MAXA + 5];

void solve() {
    int n, q; scanf("%d%d", &n, &q);
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        f[x][y] += x * y;
    }

    for (int i = 1; i <= MAXA; i++) for (int j = 1; j <= MAXA; j++) f[i][j] += f[i][j - 1];
    for (int i = 1; i <= MAXA; i++) for (int j = 1; j <= MAXA; j++) f[i][j] += f[i - 1][j];
    while (q--) {
        int xa, ya, xb, yb; scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
        printf("%lld\n", f[xb - 1][yb - 1] - f[xa][yb - 1] - f[xb - 1][ya] + f[xa][ya]);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
