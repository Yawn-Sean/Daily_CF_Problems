#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXS 450
#define MOD 998244353
using namespace std;
 
long long f[MAXN + 5][MAXS + 5];
 
void solve() {
    int n; scanf("%d", &n);
    long long ans = 0;
    for (int i = (n & 1 ? 1 : 2); i <= MAXS; i += 2) {
        int m = (n - i) / 2;
        if (m < 0) break;
        ans = (ans + f[m][i] + f[m][i - 1]) % MOD;
    }
    printf("%lld\n", ans);
}
 
int main() {
    f[0][0] = 1;
    for (int i = 1; i <= MAXN; i++) for (int j = 1; j * (j + 1) / 2 <= i; j++)
        f[i][j] = (f[i - j][j - 1] + f[i - j][j]) % MOD;
 
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
