#include <bits/stdc++.h>
#define MAXN 100
#define SIGMA 26
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
char s[MAXN + 10];

long long f[MAXN + 10][MAXN * SIGMA + 10];

int main() {
    f[0][0] = 1;
    for (int i = 1; i <= MAXN; i++) for (int j = i; j <= SIGMA * i; j++)
        for (int k = 1; k <= j && k <= SIGMA; k++) f[i][j] = (f[i][j] + f[i - 1][j - k]) % MOD;

    int tcase; scanf("%d", &tcase);
    while (tcase--) {
        scanf("%s", s + 1); n = strlen(s + 1);
        int sm = 0;
        for (int i = 1; i <= n; i++) sm += s[i] - 'a' + 1;
        printf("%lld\n", (f[n][sm] - 1 + MOD) % MOD);
    }
    return 0;
}
