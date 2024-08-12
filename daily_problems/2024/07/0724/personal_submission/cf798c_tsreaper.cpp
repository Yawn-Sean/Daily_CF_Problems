#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans, A[MAXN + 10];

int main() {
    scanf("%d", &n);
    int g = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        g = gcd(g, A[i]);
    }
    if (g > 1) { printf("YES\n0\n"); return 0; }

    for (int i = 1, j = 1; i <= n + 1; i++) {
        if (i > n || A[i] % 2 == 0) {
            int len = i - j;
            ans += len / 2 + len % 2 * 2;
            j = i + 1;
        }
    }
    printf("YES\n%d\n", ans);
    return 0;
}
