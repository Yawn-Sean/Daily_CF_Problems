#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
#define INV2 ((long long) 5e8 + 4)
using namespace std;

int n, m, A[MAXN + 5];
long long ans[MAXN + 5];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    long long now = A[n] * INV2 % MOD;
    for (int i = n - 1; i > 0; i--) {
        ans[A[i]] = (ans[A[i]] + now * INV2) % MOD;
        now = (now + A[i]) * INV2 % MOD;
    }
    ans[1] = (ans[1] + now) % MOD;

    for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    return 0;
}
