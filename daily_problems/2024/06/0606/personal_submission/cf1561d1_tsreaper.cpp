#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, MOD;
long long f[MAXN + 10];

int main() {
    scanf("%d%d", &n, &MOD);
    f[n] = 1;
    long long sm = 0;
    for (int i = n; i > 0; i--) {
        f[i] = (f[i] + sm) % MOD;
        sm = (sm + f[i]) % MOD;
        for (int l = 1, r = 0; l <= i; l = r + 1) {
            r = i / (i / l);
            if (l > 1) f[i / l] = (f[i / l] + f[i] * (r - l + 1)) % MOD;
        }
    }
    printf("%lld\n", f[1]);
    return 0;
}
