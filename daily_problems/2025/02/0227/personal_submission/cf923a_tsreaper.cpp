#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define INF ((int) 1e9)
using namespace std;

int n, ans, fac[MAXN + 5], f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) if (fac[i] == 0) for (int j = i; j <= n; j += i) fac[j] = i;
    
    for (int i = 1; i <= n; i++) f[i] = INF;
    for (int i = 4; i <= n; i++) if (i != fac[i]) {
        int x = i;
        while (x > 1) {
            f[i] = min(f[i], i - fac[x] + 1);
            x /= fac[x];
        }
    }

    ans = INF;
    int x = n;
    while (x > 1) {
        for (int i = n - fac[x] + 1; i <= n; i++) ans = min(ans, f[i]);
        x /= fac[x];
    }
    printf("%d\n", ans);
    return 0;
}
