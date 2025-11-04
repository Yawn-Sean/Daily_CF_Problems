#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MOD 998244353
using namespace std;

int n, K, A[MAXN + 5];
long long B[MAXN + 5];

long long inv[MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n - K + 1; i++) scanf("%d", &A[i]);
    
    for (int i = 1; i < n - K + 1; i++) {
        long long det = A[i + 1] - A[i];
        B[i + K] = B[i] + det;
    }
    for (int i = 1; i <= K; i++) for (int j = i + K; j <= n; j += K) B[i] = min(B[i], B[j]);

    long long t = A[1] + K;
    for (int i = 1; i <= K; i++) t += B[i];
    t--;
    if (t < K - 1) { printf("0\n"); return 0; }

    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    long long ans = 1;
    t %= MOD;
    for (int i = 1; i <= K - 1; i++) ans = ans * (t - i + 1) % MOD * inv[i] % MOD;
    printf("%lld\n", ans);
    return 0;
}
