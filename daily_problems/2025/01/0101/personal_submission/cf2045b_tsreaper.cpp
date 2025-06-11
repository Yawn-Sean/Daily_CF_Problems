#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, d, s; scanf("%lld%lld%lld", &n, &d, &s);
    if (d < s) { printf("%lld\n", s); return 0; }
    long long ans = (d / s * s) * 2;
    if (ans <= n) { printf("%lld\n", ans); return 0; }
    long long cnt = n / s;
    if (cnt == 1) {
        printf("%lld\n", s);
    } else if (cnt & 1) {
        for (int i = 2; 1LL * i * i <= cnt; i++) if (cnt % i == 0) {
            if (cnt / i * (i - 1) * s <= d) printf("%lld\n", cnt * s);
            else printf("%lld\n", (cnt - 1) * s);
            return 0;
        }
        if ((cnt - 1) * s <= d) printf("%lld\n", cnt * s);
        else printf("%lld\n", (cnt - 1) * s);
    } else {
        printf("%lld\n", cnt * s);
    }
    return 0;
}
