#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];

int main() {
    int n; scanf("%d", &n);
    int mn = 1e9;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), mn = min(mn, A[i]);

    int cnt[3] = {0};
    for (int i = 1; i <= n; i++) cnt[A[i] - mn]++;

    if (cnt[2] == 0) {
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
        return 0;
    }

    int best = n + 1, ans[3];
    for (int i = 0; i <= n; i++) {
        int y = cnt[1] + 2 * cnt[2] - (n - i);
        int x = n - i - y;
        if (x >= 0 && y >= 0) {
            int t = min(cnt[0], i) + min(cnt[1], x) + min(cnt[2], y);
            if (t < best) {
                best = t;
                ans[0] = i; ans[1] = x; ans[2] = y;
            }
        }
    }

    printf("%d\n", best);
    for (int k = 0; k < 3; k++) for (int i = 1; i <= ans[k]; i++) printf("%d ", mn + k);
    printf("\n");
    return 0;
}
