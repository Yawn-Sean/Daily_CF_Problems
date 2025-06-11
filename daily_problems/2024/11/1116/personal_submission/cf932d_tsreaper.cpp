#include <bits/stdc++.h>
#define MAXQ ((int) 4e5)
#define MAXP 20
using namespace std;

int n;
long long A[MAXQ + 5];

int f[MAXQ + 5][MAXP], d[MAXQ + 5];
long long g[MAXQ + 5];

int main() {
    int q; scanf("%d", &q);
    d[n = 1] = 1; A[0] = 1e18;
    long long ans = 0;
    while (q--) {
        int op;
        long long x, y; scanf("%d%lld%lld", &op, &x, &y);
        x ^= ans; y ^= ans;
        if (op == 1) {
            A[++n] = y;
            if (A[x] < y) {
                for (int p = MAXP - 1; p >= 0; p--) if (A[f[x][p]] < y) x = f[x][p];
                x = f[x][0];
            }
            f[n][0] = x; d[n] = d[x] + 1;
            for (int p = 1; p < MAXP; p++) f[n][p] = f[f[n][p - 1]][p - 1];
            g[n] = g[f[n][0]] + y;
        } else {
            long long sm = 0;
            ans = 0;
            for (int p = MAXP - 1; p >= 0; p--) if ((1 << p) <= d[x]) {
                long long det = g[x] - g[f[x][p]];
                if (sm + det <= y) {
                    sm += det;
                    ans += 1 << p;
                    x = f[x][p];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
