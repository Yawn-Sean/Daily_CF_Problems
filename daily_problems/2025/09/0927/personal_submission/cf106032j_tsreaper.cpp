#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((int) 1e9)
using namespace std;

int n, m, q, A[MAXN + 5];
int cnt[MAXN + 5], f[MAXN + 5];

void solve() {
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < m; i++) cnt[i] = 0, f[i] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]); A[i]--;
        cnt[A[i]]++;
    }

    int mn = m;
    for (int i = 0; i < m; i++) if (cnt[i] & 1) mn = min(mn, i);

    if (mn < m) {
        int now = mn;
        for (int i = m - 1; i >= 0; i--) {
            if (cnt[i] & 1) now = i;
            f[i] = now;
        }
    }

    int bias = 0;
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) bias++;
        else {
            int x; scanf("%d", &x);
            int lim = f[A[x]] >= 0 ? (f[A[x]] - A[x] + m) % m : INF;
            printf("%d\n", (A[x] + min(lim, bias)) % m + 1);
        }
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
