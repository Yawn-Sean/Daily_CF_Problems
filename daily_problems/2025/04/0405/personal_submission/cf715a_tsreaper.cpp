#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    __int128 now = 2;
    for (int i = 2; i <= n + 1; i++) {
        __int128 t = 1LL * i * (i - 1);
        long long ans = (t * t - now) / (i - 1);
        printf("%lld\n", ans);
        now = t;
    }
    return 0;
}
