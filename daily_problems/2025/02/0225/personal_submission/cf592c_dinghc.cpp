#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int64 t, w, b;
    scanf("%lld%lld%lld", &t, &w, &b);
    int64 g = gcd(w, b);
    // w * (b / g) > t
    // q = t / w, r = t % w
    // q * w + r < w * (b / g) <=> t / w < b / g
    if (t / w < b / g) {
        int64 p = min(min(w, b) - 1, t);
        int64 q = t;
        int64 g1 = gcd(p, q);
        printf("%lld/%lld\n", p / g1, q / g1);
    } else {
        int64 lmp = w * (b / g);
        int64 p = t / lmp * min(w, b) + min(min(w, b) - 1, t % lmp);
        int64 q = t;
        int64 g1 = gcd(p, q);
        printf("%lld/%lld\n", p / g1, q / g1);
    }
    return 0;
}

