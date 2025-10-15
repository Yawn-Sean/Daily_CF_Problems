#include <bits/stdc++.h>
#define MAXN 5000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m;
char s1[MAXN + 5], s2[MAXN + 5];
long long ans;

long long f[2][MAXN + 5];

int main() {
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1); m = strlen(s2 + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) f[i & 1][j] = 0;
        for (int j = 1; j <= m; j++) {
            f[i & 1][j] = (f[i & 1][j] + f[i & 1][j - 1]) % MOD;
            if (s1[i] == s2[j]) f[i & 1][j] = (f[i & 1][j] + f[i & 1 ^ 1][j - 1] + 1) % MOD;
        }
        ans = (ans + f[i & 1][m]) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}
