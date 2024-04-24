#include <bits/stdc++.h>
using namespace std;

long long gao(long long a, long long b) {
    return (a + b - 1) / b;
}

void solve() {
    long long x, y, p, q; scanf("%lld%lld%lld%lld", &x, &y, &p, &q);

    if (p == 0) {
        if (x == 0) printf("0\n");
        else printf("-1\n");
        return;
    }

    if (p == 1 && q == 1) {
        if (x == y) printf("0\n");
        else printf("-1\n");
        return;
    }

    printf("%lld\n", max({gao(x, p), gao(y, q), gao(y - x, q - p)}) * q - y);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
