#include <bits/stdc++.h>
#define MAXN 4000
using namespace std;

int n, X;
char s[MAXN + 5];
long long ans;

long long f[MAXN + 5];
int cnt[MAXN * 10 + 5];

int main() {
    scanf("%d%s", &X, s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + s[i] - '0';
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) cnt[f[j] - f[i - 1]]++;
    if (X == 0) {
        long long tot = 1LL * (n + 1) * n / 2;
        long long bad = tot - cnt[0];
        printf("%lld\n", tot * tot - bad * bad);
        return 0;
    }
    for (int i = 1; i <= n * 10; i++) if (X % i == 0 && X / i <= n * 10) ans += 1LL * cnt[i] * cnt[X / i];
    printf("%lld\n", ans);
    return 0;
}
