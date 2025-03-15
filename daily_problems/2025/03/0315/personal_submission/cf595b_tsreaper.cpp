#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K, A[MAXN + 5], B[MAXN + 5];
long long ans;

long long P[10];

long long calc(long long x, int y) {
    if (x < 0) return 0;
    return x / y + 1;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n / K; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n / K; i++) scanf("%d", &B[i]);

    P[0] = 1;
    for (int i = 1; i <= K; i++) P[i] = P[i - 1] * 10;

    ans = 1;
    for (int i = 1; i <= n / K; i++) {
        long long t = calc(P[K] - 1, A[i]);
        t -= calc(P[K - 1] * (B[i] + 1) - 1, A[i]) - calc(P[K - 1] * B[i] - 1, A[i]);
        t %= MOD;
        ans = ans * t % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
