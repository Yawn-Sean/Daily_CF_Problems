#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXA ((int) 1e7)
using namespace std;

int n, m, A[MAXN + 5], B[MAXN + 5];

int fac[MAXA + 5], cnt1[MAXA + 5], cnt2[MAXA + 5];

int main() {
    scanf("%d%d", &n, &m);

    int mx = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), mx = max(mx, A[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]), mx = max(mx, B[i]);

    for (int i = 2; i <= mx; i++) if (fac[i] == 0) for (int j = i; j <= mx; j += i) fac[j] = i;

    for (int i = 1; i <= n; i++) {
        int x = A[i];
        while (x > 1) cnt1[fac[x]]++, x /= fac[x];
    }
    for (int i = 1; i <= m; i++) {
        int x = B[i];
        while (x > 1) cnt2[fac[x]]++, x /= fac[x];
    }

    for (int i = 1; i <= n; i++) {
        int x = A[i];
        while (x > 1) {
            if (cnt2[fac[x]] > 0) A[i] /= fac[x], cnt2[fac[x]]--;
            x /= fac[x];
        }
    }
    for (int i = 1; i <= m; i++) {
        int x = B[i];
        while (x > 1) {
            if (cnt1[fac[x]] > 0) B[i] /= fac[x], cnt1[fac[x]]--;
            x /= fac[x];
        }
    }

    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
    for (int i = 1; i <= m; i++) printf("%d%c", B[i], "\n "[i < m]);
    return 0;
}
