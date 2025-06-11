#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, ans[MAXN + 10];

int main() {
    scanf("%d%d", &K, &n);
    long long mn = 1LL * (n + 1) * n / 2;
    if (K < mn) { printf("NO\n"); return 0; }

    if (n == 1) { printf("YES\n%d\n", K); return 0; }
    if (n == 2) {
        if (K == 4) { printf("NO\n"); return 0; }
        printf("YES\n");
        if (K % 2) printf("%d %d\n", K / 2, K / 2 + 1);
        else printf("%d %d\n", K / 2 - 1, K / 2 + 1);
        return 0;
    }
    if (n == 3 && K == 8) { printf("NO\n"); return 0; }

    int r = (K - mn) / n;
    for (int i = 1; i <= n; i++) ans[i] = i + r;
    K -= mn + r * n;
    for (int i = n; K > 0; i--, K--) {
        if (K == 1 && i == 2 && ans[1] == 1) ans[n]++;
        else ans[i]++;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
