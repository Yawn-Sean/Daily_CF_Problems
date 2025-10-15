#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &a, &b, &x1, &y1, &x2, &y2);
    int s1 = x1 + y1, s2 = x2 + y2;
    if (s1 > s2) swap(s1, s2);
    int d1 = x1 - y1, d2 = x2 - y2;
    if (d1 > d2) swap(d1, d2);
    auto f = [&] (int s1, int s2, int m) -> int {
        long long k;
        if (s1 < 0) {
            k = 1LL * s1 / (m * 2) * (m * 2);
        } else {
            k = 1LL * (s1 + m * 2 - 1) / (m * 2) * (m * 2);
        }
        if (s2 < k) return 0;
        return (s2 - k) / (m * 2) + 1;
    };
    int p = f(s1, s2, a);
    int q = f(d1, d2, b);
    printf("%lld\n", max(p, q));
    return 0;
}

