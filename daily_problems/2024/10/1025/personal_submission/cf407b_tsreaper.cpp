#include <bits/stdc++.h>
#define MAXN 1000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, A[MAXN + 10];
long long f[MAXN + 10], g[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    f[1] = g[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = ((i - A[i] + 1) + g[i - 1] - g[A[i] - 1] + MOD) % MOD;
        g[i] = (g[i - 1] + f[i]) % MOD;
    }
    printf("%lld\n", (g[n] + n) % MOD);
    return 0;
}
