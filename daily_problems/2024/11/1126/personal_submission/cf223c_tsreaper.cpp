#include <bits/stdc++.h>
#define MAXN 2000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K, A[MAXN + 5];

long long inv[MAXN + 5], C[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    if (K == 0) {
        for (int i = 1; i <= n; i++) printf("%d%c", A[i], "\n "[i < n]);
        return 0;
    }

    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

    C[0] = 1;
    for (int i = 1; i <= n; i++) C[i] = C[i - 1] * inv[i] % MOD * (K - 1 + i) % MOD;

    for (int i = 1; i <= n; i++) {
        long long sm = 0;
        for (int j = 1; j <= i; j++) sm = (sm + A[j] * C[i - j]) % MOD;
        printf("%lld%c", sm, "\n "[i < n]);
    }
    return 0;
}
