#include <bits/stdc++.h>
#define MAXN 100
#define MAXL 3000
#define MAXA 100
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, L, A[MAXN + 5], B[MAXN + 5];
long long ans;

long long f[MAXL + 5][MAXN + 5][2], g[MAXL + 5][MAXA + 5];

int main() {
    scanf("%d%d", &n, &L);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]);

    for (int i = 1; i <= L; i++) for (int j = 1; j <= n; j++) for (int k = 0; k < (A[j] == B[j] ? 1 : 2); k++) {
        int len = (k ? B[j] : A[j]), wid = (k ? A[j] : B[j]);
        if (i < len) continue;
        if (i == len) f[i][j][k] = 1;
        else {
            f[i][j][k] = g[i - len][len];
            if (B[j] == len) f[i][j][k] = (f[i][j][k] - f[i - len][j][0] + MOD) % MOD;
            if (A[j] == len) f[i][j][k] = (f[i][j][k] - f[i - len][j][1] + MOD) % MOD;
        }
        g[i][wid] = (g[i][wid] + f[i][j][k]) % MOD;
    }

    for (int j = 1; j <= MAXA; j++) ans = (ans + g[L][j]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
