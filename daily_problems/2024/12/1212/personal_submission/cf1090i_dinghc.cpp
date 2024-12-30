#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int N = 10'000'000;
int64 a[N];
constexpr int64 MSK = (1LL << 32) - 1;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, l, r;
        int64 x, y, z, b1, b2;
        scanf("%d%d%d %lld%lld%lld%lld%lld", &n, &l, &r, &x, &y, &z, &b1, &b2);
        a[0] = b1 % (1LL + r - l) + l;
        a[1] = b2 % (1LL + r - l) + l;
        for (int i = 2; i < n; i++) {
            b1 = (x * b1 + y * b2 + z) & MSK;
            a[i] = b1 % (1LL + r - l) + l;
            swap(b1, b2);
        }
        int64 ans = LONG_LONG_MAX;
        int64 mn = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > mn) ans = min(ans, a[i] * mn);
            mn = min(mn, a[i]);
        }
        int64 mx = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] < mx) ans = min(ans, a[i] * mx);
            mx = max(mx, a[i]);
        }
        if (ans < LONG_LONG_MAX) printf("%lld\n", ans);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}

