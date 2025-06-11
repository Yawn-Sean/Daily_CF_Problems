#include <bits/stdc++.h>
#define MAXN 2000
#define MAXM ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m;
long long ans;
char s[MAXM + 5];

long long f[2][2][MAXN + 5];

void update(long long &a, long long b) { a = (a + b) % MOD; }

int main() {
    scanf("%d%d%s", &n, &m, s + 1); n -= m;

    int mn = 0, now = 0;
    for (int i = 1; i <= m; i++) {
        if (s[i] == '(') now++;
        else now--;
        mn = min(mn, now);
    }
    if (mn < -n || now > n) { printf("0\n"); return 0; }

    f[0][0][0] = 1;
    if (mn >= 0) f[0][1][now] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) for (int k = 0; k <= n; k++) f[i & 1][j][k] = 0;
        for (int j = 0; j < 2; j++) for (int k = 0; k <= n; k++) {
            if (k < n) update(f[i & 1][j][k + 1], f[i & 1 ^ 1][j][k]);
            if (k > 0) update(f[i & 1][j][k - 1], f[i & 1 ^ 1][j][k]);
        }
        for (int k = -mn; k <= n && k + now <= n; k++) update(f[i & 1][1][k + now], f[i & 1][0][k]);
    }

    printf("%lld\n", f[n & 1][1][0]);
    return 0;
}
