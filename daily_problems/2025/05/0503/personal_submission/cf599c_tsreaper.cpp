#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans, A[MAXN + 5];
int f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    f[1] = A[1];
    for (int i = 2; i <= n; i++) f[i] = max(f[i - 1], A[i]);
    g[n] = A[n];
    for (int i = n - 1; i > 0; i--) g[i] = min(g[i + 1], A[i]);

    ans = 1;
    for (int i = 1; i < n; i++) if (f[i] <= g[i + 1]) ans++;
    printf("%d\n", ans);
    return 0;
}
