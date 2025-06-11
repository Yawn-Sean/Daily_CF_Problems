#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, r, x, y;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    if (y % x != 0) {
        printf("0\n");
        return 0;
    }
    int ans = 0;
    l = (l + x - 1) / x;
    r = r / x;
    y = y / x;
    for (int p = 1; p * p <= y; p++) {
        if (y % p == 0) {
            int q = y / p;
            if (gcd(p, q) == 1 && p >= l && p <= r && q >= l && q <= r) {
                ans += p == q ? 1 : 2;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

