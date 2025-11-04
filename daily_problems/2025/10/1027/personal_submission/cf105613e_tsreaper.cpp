#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXA ((int) 1e6)
using namespace std;

int n, K, ans[MAXN + 5];

int main() {
    int n, K; scanf("%d%d", &n, &K);
    if (K > 1LL * n * (n - 1) / 2) { printf("-1\n"); return 0; }

    int rem = -1, now = MAXA;
    for (int i = 1; i <= n; i++) {
        if (K > n - i) {
            ans[i] = 2;
            K -= n - i;
        } else if (rem < 0) {
            ans[i] = 4;
            rem = K;
            K = 0;
        } else if (rem > 0) {
            ans[i] = MAXA / 2 + rem * 4;
            rem--;
        } else {
            while (now % 4 == 0) now -= 2;
            ans[i] = now;
            now -= 2;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
