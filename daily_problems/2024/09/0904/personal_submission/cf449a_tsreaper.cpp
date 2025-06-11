#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, K; scanf("%d%d%d", &n, &m, &K);
    int t = 1;
    long long ans = 0;
    while (t <= n) {
        int dn = n / t;
        t = n / dn;
        int dm = m / max(1, K - (t - 1) + 1);
        ans = max(ans, 1LL * dn * dm);
        t++;
    }
    printf("%lld\n", ans > 0 ? ans : -1);
    return 0;
}
