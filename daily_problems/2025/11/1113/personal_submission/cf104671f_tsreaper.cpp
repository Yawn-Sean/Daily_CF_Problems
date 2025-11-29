#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 30
using namespace std;

int n, K, q, f[MAXN + 5][MAXP];

int main() {
    scanf("%d%d%d", &n, &K, &q);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        for (int p = 0; p < MAXP; p++) f[i][p] = f[i - 1][p];
        if ((x & K) == K) for (int p = 0; p < MAXP; p++) if (x >> p & 1 ^ 1) f[i][p]++;
    }
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        bool ok = true;
        for (int p = 0; p < MAXP; p++) if (K >> p & 1 ^ 1) {
            if (f[r][p] - f[l - 1][p] == 0) { ok = false; break; }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
