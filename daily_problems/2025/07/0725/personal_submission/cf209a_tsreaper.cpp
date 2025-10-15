#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
long long f[MAXN + 5][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        f[i][i & 1] = (f[i - 1][i & 1] + f[i - 1][i & 1 ^ 1] + 1) % MOD;
        f[i][i & 1 ^ 1] = f[i - 1][i & 1 ^ 1];
    }
    printf("%lld\n", (f[n][0] + f[n][1]) % MOD);
    return 0;
}
