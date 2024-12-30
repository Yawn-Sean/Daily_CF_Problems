#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans, A[MAXN + 10];
int f[MAXN + 10], g[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) f[i] = min(f[i - 1] + 1, A[i]);
    for (int i = n; i > 0; i--) g[i] = min(g[i + 1] + 1, A[i]);
    for (int i = 1; i <= n; i++) ans = max(ans, min(f[i], g[i]));
    printf("%d\n", ans);
    return 0;
}
