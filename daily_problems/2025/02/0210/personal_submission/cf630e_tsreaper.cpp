#include <bits/stdc++.h>
using namespace std;

int main() {
    int xa, ya, xb, yb; scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
    long long cnt = (xb - xa) / 2 + 1;
    int h = yb - ya + 1;
    long long ans = (cnt * 2 - 1) * (h / 2);
    if (h & 1) ans += cnt;
    printf("%lld\n", ans);
    return 0;
}
