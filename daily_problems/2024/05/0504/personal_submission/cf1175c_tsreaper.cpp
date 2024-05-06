#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K, A[MAXN + 10];

void solve() {
    scanf("%d%d", &n, &K); K++;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int ans = 0, best = 2e9;
    for (int i = 1, j = K; j <= n; i++, j++) {
        int t = A[j] - A[i];
        if (t < best) ans = (A[i] + A[j]) / 2, best = t;
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
