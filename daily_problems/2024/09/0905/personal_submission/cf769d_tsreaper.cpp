#include <bits/stdc++.h>
#define MAXA ((int) 1e4)
using namespace std;

int n, K, cnt[MAXA + 10];
long long ans;

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    for (int x = 0; x <= MAXA; x++) {
        if (K == 0) ans += 1LL * cnt[x] * (cnt[x] - 1) / 2;
        else for (int y = x + 1; y <= MAXA; y++) if (__builtin_popcount(x ^ y) == K) ans += 1LL * cnt[x] * cnt[y];
    }
    printf("%lld\n", ans);
    return 0;
}
