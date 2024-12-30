#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define BASE 33
#define SMOD ((long long) 1e18 + 17)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m;
char s1[MAXN + 10], s2[MAXN + 10];

__int128 P[MAXN + 10];
int last[MAXN + 10];
long long f[MAXN + 10], g[MAXN + 10];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1); m = strlen(s2 + 1);
    if (n < m) { printf("0\n"); return 0; }
    
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * BASE % SMOD;
    __int128 goal = 0;
    for (int i = 1; i <= m; i++) goal = (goal * BASE + s2[i] - 'a') % SMOD;
    __int128 now = 0;
    for (int i = 1; i <= n; i++) {
        now = (now * BASE + s1[i] - 'a') % SMOD;
        if (i > m) now = (now - (s1[i - m] - 'a') * P[m] % SMOD + SMOD) % SMOD;
        if (i >= m && now == goal) last[i] = i;
        else last[i] = last[i - 1];
    }

    f[0] = g[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (last[i] > 0) f[i] = (f[i] + g[last[i] - m]) % MOD;
        g[i] = (g[i - 1] + f[i]) % MOD;
    }
    printf("%lld\n", (f[n] - 1 + MOD) % MOD);
    return 0;
}
