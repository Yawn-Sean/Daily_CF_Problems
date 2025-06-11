#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 30
#define MOD ((int) 1e9 + 7)
using namespace std;

long long P[MAXN + 5];

int main() {
    int n; scanf("%d", &n);
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;

    int cnt[MAXP] = {0};
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[__lg(x & (-x))]++;
    }

    int rem = n - cnt[0];
    long long ans = (P[cnt[0]] - 1 + MOD) * P[rem] % MOD;
    for (int i = 1; i < MAXP; i++) {
        rem -= cnt[i];
        if (cnt[i]) ans = (ans + (P[cnt[i] - 1] - 1 + MOD) * P[rem]) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
