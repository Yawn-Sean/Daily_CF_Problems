#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q, A[MAXN + 10], B[MAXN + 10];

int f[MAXN + 10], g[MAXN + 10];

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + A[i] % 2;
    for (int i = 1; i <= n; i++) g[i] = g[i - 1] + B[i] % 2;
    while (q--) {
        int ra, ca, rb, cb; scanf("%d%d%d%d", &ra, &ca, &rb, &cb);
        int d1 = max(ra, rb) - min(ra, rb) + 1;
        int v1 = f[max(ra, rb)] - f[min(ra, rb) - 1];
        int d2 = max(ca, cb) - min(ca, cb) + 1;
        int v2 = g[max(ca, cb)] - g[min(ca, cb) - 1];
        if ((v1 == 0 || v1 == d1) && (v2 == 0 || v2 == d2)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
