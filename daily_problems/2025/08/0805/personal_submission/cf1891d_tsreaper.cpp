#include <bits/stdc++.h>
#define MAXP 60
#define MOD ((int) 1e9 + 7)
using namespace std;

void solve() {
    long long L, R; scanf("%lld%lld", &L, &R);

    long long ans = 0;
    for (int p = 2; p < MAXP; p++) {
        __int128 now = 1;
        for (int i = 1; ; i++) {
            now *= p;
            if (now > R) break;
            
            long long l = now;
            l = max({l, L, 1LL << p});

            __int128 nxt = now * p;
            long long r = R;
            if (r > nxt - 1) r = nxt - 1;
            r = min(r, (1LL << (p + 1)) - 1);

            if (l <= r) ans = (ans + (r - l + 1) % MOD * i) % MOD;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
