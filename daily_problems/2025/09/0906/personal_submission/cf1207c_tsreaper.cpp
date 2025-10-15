#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;

int n, a, b;
char s[MAXN + 5];

long long f[MAXN + 5][2];

void solve() {
    scanf("%d%d%d%s", &n, &a, &b, s + 1);
    for (int i = 0; i <= n; i++) for (int j = 0; j < 2; j++) f[i][j] = INF;
    f[0][0] = b;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '1' && s[i + 1] != '1')
            f[i][0] = min(f[i - 1][0] + a, f[i - 1][1] + a * 2) + b;
        f[i][1] = min(f[i - 1][0] + a * 2, f[i - 1][1] + a) + b * 2;
    }
    printf("%lld\n", f[n][0]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
