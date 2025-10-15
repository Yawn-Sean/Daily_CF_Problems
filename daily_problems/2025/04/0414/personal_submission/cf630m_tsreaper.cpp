#include <bits/stdc++.h>
using namespace std;

int calc(long long x) {
    x = (x % 360 + 360) % 360;
    return min(x, 360 - x);
}

int main() {
    long long x; scanf("%lld", &x);
    int ans = 0, best = calc(x);
    for (int i = 1; i < 4; i++) {
        int t = calc(x - i * 90);
        if (t < best) ans = i, best = t;
    }
    printf("%d\n", ans);
    return 0;
}
