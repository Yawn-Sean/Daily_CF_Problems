#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, ans, A[MAXN + 5], B[MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]);

    int tot = 0, bad = 0;
    for (int i = 1; i <= m; i++) if (B[i] > 0) tot += B[i], bad++;
    ans = n + 1;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && bad > 0) {
            int t = --B[A[j]];
            if (t == 0) bad--;
            j++;
        }
        if (bad == 0) ans = min(ans, j - i);
        int t = B[A[i]]++;
        if (t == 0) bad++;
    }

    if (ans > n) printf("-1\n");
    else printf("%d\n", ans - tot);
    return 0;
}
