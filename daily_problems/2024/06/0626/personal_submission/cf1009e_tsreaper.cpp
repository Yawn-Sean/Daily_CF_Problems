#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD 998244353
using namespace std;

int n, A[MAXN + 10];
long long P[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;

    long long sm = 0, now = 0;
    for (int i = 1; i <= n; i++) {
        sm = (sm + now + P[n - i] * A[i]) % MOD;
        now = (now + P[n - 1 - i] * A[i]) % MOD;
    }
    printf("%lld\n", sm);
    return 0;
}
