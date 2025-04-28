#include <bits/stdc++.h>
using namespace std;

long long calc(long long l, long long r, long long mod) {
    if (l > r) swap(l, r);
    if (l < 0) {
        long long t = (-l + mod - 1) / mod;
        l += t * mod; r += t * mod;
    }
    return r / mod - (l + mod - 1) / mod + 1;
}

int main() {
    long long a, b, xa, ya, xb, yb;
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &xa, &ya, &xb, &yb);
    printf("%lld\n", max(calc(xa + ya, xb + yb, a * 2), calc(xa - ya, xb - yb, b * 2)));
    return 0;
}
