#include <bits/stdc++.h>
#define MAXP 30
using namespace std;

void solve() {
    int n, MOD; scanf("%d%d", &n, &MOD);

    int p;
    for (p = MAXP; n >> p & 1 ^ 1; p--);

    long long ans = 0;
    for (int i = 0; i <= p; i++) {
        int cnt;
        if (i == 0) cnt = 1;
        else if (i == p) cnt = n - (1 << p) + 1;
        else cnt = 1 << i;
        ans = ((ans + 1) * cnt + ans) % MOD;
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
