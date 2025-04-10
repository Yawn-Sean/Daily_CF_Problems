#include <bits/stdc++.h>
#define MAXN 2000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K, A[MAXN + 5];
long long ans;

long long f[MAXN + 5][MAXN + 5][2], P[MAXN + 5];

void update(long long &a, long long b) { a = (a + b) % MOD; }

int main() {
    scanf("%d%d", &n, &K);
    int m = 1 << (K - 2);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;
    int zero = 0;
    for (int i = 1; i <= n; i++) zero += (A[i] == 0 ? 1 : 0);

    A[0] = 4;
    f[0][0][1] = 1;
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0 || A[i] == 2) {
            for (int j = 1; j < m; j++) update(f[i][0][0], (f[i - 1][j][0] + f[i - 1][j][1]) % MOD);
            update(f[i][0][0], f[i - 1][0][1]);
            if (A[i - 1] == 0 || A[i - 1] == 2) {
                for (int j = 2; j <= m; j++) update(f[i][j][0], (f[i - 2][j - 1][0] + f[i - 2][j - 1][1]) % MOD);
                update(f[i][1][0], f[i - 2][0][1]);
            }
        }
        if (A[i] == 0 || A[i] == 4) {
            for (int j = 1; j <= m; j++) update(f[i][j][1], (f[i - 1][j - 1][0] + f[i - 1][j - 1][1]) % MOD);
        }
        if (A[i] == 0) zero--;
        update(ans, (f[i][m][0] + f[i][m][1]) * P[zero] % MOD);
    }
    printf("%lld\n", ans);
    return 0;
}
