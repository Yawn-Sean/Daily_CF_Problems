#include <bits/stdc++.h>
#define MAXN 2000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m;
char MAP[MAXN + 5][MAXN + 5];

long long f[2][MAXN + 5][MAXN + 5];
int g[2][MAXN + 5][MAXN + 5];

void update(long long &a, long long b) {
    a = (a + b % MOD + MOD) % MOD;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    if (n == 1 && m == 1) { printf("1\n"); return 0; }

    for (int i = n; i > 0; i--) for (int j = m; j > 0; j--) {
        g[0][i][j] = g[0][i][j + 1] + (MAP[i][j] == '.' ? 1 : 0);
        g[1][i][j] = g[1][i + 1][j] + (MAP[i][j] == '.' ? 1 : 0);
    }

    f[0][1][1] = f[1][1][1] = 1;
    f[0][1][2] = f[1][2][1] = MOD - 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        update(f[0][i][j], f[0][i][j - 1]);
        int d = g[1][i + 1][j];
        update(f[1][i + 1][j], f[0][i][j]);
        update(f[1][i + d + 1][j], -f[0][i][j]);

        update(f[1][i][j], f[1][i - 1][j]);
        d = g[0][i][j + 1];
        update(f[0][i][j + 1], f[1][i][j]);
        update(f[0][i][j + d + 1], -f[1][i][j]);
    }

    printf("%lld\n", (f[0][n][m] + f[1][n][m]) % MOD);
    return 0;
}
