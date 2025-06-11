#include <bits/stdc++.h>
#define MAXK 2000
#define MOD 998244353
using namespace std;

long long f[2][MAXK + 10][4];
int X[4][4] = {
    0, 1, 1, 1,
    0, 0, 2, 0,
    0, 2, 0, 0,
    1, 1, 1, 0,
};

int main() {
    int n, K; scanf("%d%d", &n, &K);
    f[1][1][0] = f[1][1][3] = f[1][2][1] = f[1][2][2] = 1;
    for (int i = 1; i < n; i++) {
        for (int k = 1; k <= K; k++) for (int msk = 0; msk < 4; msk++) f[i & 1 ^ 1][k][msk] = 0;
        for (int k = 1; k <= K && k <= i * 2; k++) for (int msk = 0; msk < 4; msk++) for (int mm = 0; mm < 4; mm++) {
            int kk = k + X[msk][mm];
            f[i & 1 ^ 1][kk][mm] = (f[i & 1 ^ 1][kk][mm] + f[i & 1][k][msk]) % MOD;
        }
    }

    long long ans = 0;
    for (int msk = 0; msk < 4; msk++) ans = (ans + f[n & 1][K][msk]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
