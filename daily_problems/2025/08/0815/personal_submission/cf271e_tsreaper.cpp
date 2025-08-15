#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);

    int g = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        g = gcd(g, x - 1);
    }

    long long ans = 0;
    auto gao = [&](long long x) {
        for (; x + 1 <= m; x *= 2) ans += m - x;
    };

    for (int i = 1; i * i <= g; i++) if (g % i == 0) {
        if (i % 2) gao(i);
        if (i != g / i && (g / i) % 2) gao(g / i);
    }
    printf("%lld\n", ans);
    return 0;
}
