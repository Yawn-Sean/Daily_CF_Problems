#include <bits/stdc++.h>
using namespace std;

int x, y, n;
long long ans1, ans2, w1, w2;

void gao(long long a, long long b) {
    long long v1 = abs(x * b - y * a), v2 = y * b;
    long long g = gcd(v1, v2);
    v1 /= g; v2 /= g;

    if (ans2 == 0 || w1 * v2 > w2 * v1) {
        ans1 = a; ans2 = b;
        w1 = v1; w2 = v2;
    }
}

int main() {
    scanf("%d%d%d", &x, &y, &n);
    for (int i = 1; i <= n; i++) {
        long long w = 1LL * x * i / y;
        gao(w, i);
        w = (1LL * x * i + y - 1) / y;
        gao(w, i);
    }
    printf("%lld/%lld\n", ans1, ans2);
    return 0;
}
