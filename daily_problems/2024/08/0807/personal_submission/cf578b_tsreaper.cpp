#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 10], f[MAXN + 10], g[MAXN + 10];

int main() {
    int K, x;
    scanf("%d%d%d", &n, &K, &x);
    long long p = 1;
    while (K--) p *= x;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] | A[i];
    for (int i = n; i > 0; i--) g[i] = g[i + 1] | A[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i - 1] | g[i + 1] | (A[i] * p));
    printf("%lld\n", ans);
    return 0;
}
