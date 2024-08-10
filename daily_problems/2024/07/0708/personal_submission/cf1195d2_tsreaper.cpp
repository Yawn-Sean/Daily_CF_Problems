#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 10
#define MOD 998244353
using namespace std;

int n, A[MAXN + 10];
long long ans;

int cnt[MAXP + 5];
long long P[MAXP * 2 + 5];

int main() {
    P[0] = 1;
    for (int i = 1; i <= MAXP * 2; i++) P[i] = P[i - 1] * 10 % MOD;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        int len = 0;
        for (int x = A[i]; x; x /= 10) len++;
        cnt[len]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int x = A[i], pos = 0; x; x /= 10, pos++) {
            int d = x % 10;
            for (int j = 1; j <= MAXP; j++) {
                if (j > pos) ans = (ans + d * P[pos * 2] % MOD * cnt[j]) % MOD;
                else ans = (ans + d * P[pos + j] % MOD * cnt[j]) % MOD;
                if (j > pos + 1) ans = (ans + d * P[pos * 2 + 1] % MOD * cnt[j]) % MOD;
                else ans = (ans + d * P[pos + j] % MOD * cnt[j]) % MOD;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
