#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
char s1[MAXN + 10], s2[MAXN + 10];

long long fac[MAXN + 10], ifac[MAXN + 10];

void gao(long long &x, int from, int to) {
    x = x * fac[from] % MOD;
    x = x * ifac[to] % MOD;
}

long long solve(char *s, char *p) {
    int cnt[26] = {0};
    for (int i = 1; i <= n; i++) cnt[p[i] - 'a']++;

    long long now = fac[n];
    for (int i = 0; i < 26; i++) now = now * ifac[cnt[i]] % MOD;

    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        int lim = s[i] - 'a';
        for (int j = 0; j < lim; j++) if (cnt[j] > 0) {
            gao(now, cnt[j], cnt[j] - 1);
            gao(now, n - i, n - i + 1);
            ret = (ret + now) % MOD;
            gao(now, cnt[j] - 1, cnt[j]);
            gao(now, n - i + 1, n - i);
        }
        if (cnt[lim] == 0) break;
        gao(now, cnt[lim], cnt[lim] - 1);
        gao(now, n - i, n - i + 1);
        cnt[lim]--;
    }
    return ret;
}

int main() {
    scanf("%s%s", s1 + 1, s2 + 1); n = strlen(s1 + 1);

    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= n; i++) ifac[i] = ifac[i] * ifac[i - 1] % MOD;

    printf("%lld\n", (solve(s2, s1) - solve(s1, s1) - 1 + MOD + MOD) % MOD);
    return 0;
}
