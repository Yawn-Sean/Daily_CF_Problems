#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y, m; scanf("%lld%lld%lld", &x, &y, &m);
    if (x > y) swap(x, y);

    if (m <= y) printf("0\n");
    else if (y <= 0) printf("-1\n");
    else {
        long long ans = 0;
        if (x < 0) {
            long long t = (-x + y - 1) / y;
            x += t * y;
            ans += t;
        }
        while (y < m) {
            x += y;
            if (x > y) swap(x, y);
            ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
