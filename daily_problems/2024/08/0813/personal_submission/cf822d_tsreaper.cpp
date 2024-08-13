#include <bits/stdc++.h>
#define MAXR ((int) 5e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

long long ans, K[MAXR + 10];
int now[MAXR + 10];
bool flag[MAXR + 10];

int main() {
    int T, L, R; scanf("%d%d%d", &T, &L, &R);

    K[L] = 1;
    for (int i = L + 1; i <= R; i++) K[i] = K[i - 1] * T % MOD;

    for (int i = L; i <= R; i++) now[i] = i;
    for (int i = 2; i <= R; i++) if (!flag[i]) for (int j = i; j <= R; j += i) {
        flag[j] = true;
        if (j < L) continue;

        long long t = 0;
        while (now[j] % i == 0) {
            now[j] /= i;
            t = (t + 1LL * i * (i - 1) / 2 % MOD * now[j]) % MOD;
        }
        ans = (ans + K[j] * t) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
