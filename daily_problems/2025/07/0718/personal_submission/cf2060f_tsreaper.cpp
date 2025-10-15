#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 20
#define MOD 998244353
using namespace std;

vector<int> fac[MAXN + 5];
long long ifac[MAXP + 5], f[MAXN + 5][MAXP];

long long C(int a, int b) {
    if (a < b) return 0;
    long long ret = 1;
    for (int i = 1; i <= b; i++) ret = ret * (a - i + 1) % MOD * ifac[i] % MOD;
    return ret;
}

void solve() {
    int n, m; scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) for (int j = 0; j < MAXP; j++) f[i][j] = 0;
    f[1][0] = 1;
    for (int i = 2; i <= n; i++) for (int j = 1; j < MAXP; j++) for (int x : fac[i])
        f[i][j] = (f[i][j] + f[i / x][j - 1]) % MOD;

    for (int i = 1; i <= n; i++) {
        long long ans = 0, c = 1;
        for (int j = 0; j < MAXP; j++) {
            c = c * (m - j + 1) % MOD * ifac[j + 1] % MOD;
            ans = (ans + c * f[i][j]) % MOD;
        }
        if (i == 1) ans = (ans - 1 + MOD) % MOD;
        printf("%lld%c", ans, "\n "[i < n]);
    }
}

int main() {
    for (int i = 2; i <= MAXN; i++) for (int j = i; j <= MAXN; j += i) fac[j].push_back(i);
    ifac[1] = 1;
    for (int i = 2; i <= MAXP; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
