#include <bits/stdc++.h>
#define MAXN 1000
#define MAXP 17
#define MOD 998244353
using namespace std;

int n, q;
char s[MAXN + 5];

long long f[1 << MAXP][MAXP + 1], pw[MAXP + 1][MAXN + 5];
int g[MAXN + 5];

bool gao(int l, int r, int &cnt, int &msk) {
    if (s[l] == '?' && s[r] == '?') cnt++;
    else if (s[l] == '?') msk |= 1 << (s[r] - 'a');
    else if (s[r] == '?') msk |= 1 << (s[l] - 'a');
    else if (s[l] != s[r]) return false;
    for (int k = 1; k <= MAXP; k++) f[msk][k] = (f[msk][k] + pw[k][cnt + g[n] - g[r] + g[l - 1]]) % MOD;
    return true;
}

int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 0; i <= MAXP; i++) {
        pw[i][0] = 1;
        for (int j = 1; j <= n; j++) pw[i][j] = pw[i][j - 1] * i % MOD;
    }
    for (int i = 1; i <= n; i++) g[i] = g[i - 1] + (s[i] == '?' ? 1 : 0);

    for (int i = 1; i <= n; i++) {
        int cnt = 0, msk = 0;
        for (int l = i, r = i; l > 0 && r <= n; l--, r++)
            if (!gao(l, r, cnt, msk)) break;
    }
    for (int i = 1; i < n; i++) {
        int cnt = 0, msk = 0;
        for (int l = i, r = i + 1; l > 0 && r <= n; l--, r++)
            if (!gao(l, r, cnt, msk)) break;
    }
    for (int p = 0; p < MAXP; p++) for (int msk = 0; msk < (1 << MAXP); msk++) if (msk >> p & 1)
        for (int k = 1; k <= MAXP; k++) f[msk][k] = (f[msk][k] + f[msk ^ (1 << p)][k]) % MOD;

    scanf("%d", &q);
    while (q--) {
        char qry[20]; scanf("%s", qry);
        int msk = 0;
        for (int i = 0; qry[i]; i++) msk |= 1 << (qry[i] - 'a');
        printf("%lld\n", f[msk][__builtin_popcount(msk)]);
    }
    return 0;
}
