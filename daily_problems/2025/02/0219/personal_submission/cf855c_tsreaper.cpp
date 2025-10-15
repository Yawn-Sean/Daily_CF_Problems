#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXX 10
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m, K, X;
long long ans;

vector<int> e[MAXN + 5];
long long f[MAXN + 5][3][MAXX + 1];

void dp(int sn, int fa) {
    long long g[MAXX + 1], h[MAXX + 1], p[MAXX + 1];
    memset(g, 0, sizeof(g)); memset(h, 0, sizeof(h)); memset(p, 0, sizeof(p));
    g[0] = h[0] = p[0] = 1;

    for (int fn : e[sn]) if (fn != fa) {
        dp(fn, sn);
        for (int i = X; i >= 0; i--) {
            long long gg = 0, hh = 0, pp = 0;
            for (int j = 0; j <= i; j++) {
                gg = (gg + g[i - j] * f[fn][0][j]) % MOD;
                hh = (hh + h[i - j] * (f[fn][0][j] + f[fn][1][j] + f[fn][2][j])) % MOD;
                pp = (pp + p[i - j] * (f[fn][0][j] + f[fn][2][j])) % MOD;
            }
            g[i] = gg; h[i] = hh; p[i] = pp;
        }
    }

    for (int i = 0; i <= X; i++) {
        f[sn][0][i] = h[i] * (K - 1) % MOD;
        f[sn][2][i] = p[i] * (m - K) % MOD;
    }
    for (int i = 1; i <= X; i++) f[sn][1][i] = g[i - 1];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    scanf("%d%d", &K, &X);

    dp(1, 0);
    for (int j = 0; j < 3; j++) for (int k = 0; k <= X; k++) ans = (ans + f[1][j][k]) % MOD;
    printf("%lld\n", ans);
    return 0;
}
