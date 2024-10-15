#include <bits/stdc++.h>

using namespace std;

using li = long long;
constexpr li MXH = 1'000'000'000;
constexpr int N = 200'000;
li a[N];
li b[N];
li sum[N + 1];

int main() {
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    sum[0] = 0LL;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (b[i - 1] - a[i - 1]);
    }
    li ans = 0;
    for (int i = 0; i < n; i++) {
        li x = a[i];
        li lo = 0, hi = MXH * 2;
        while (lo <= hi) {
            li d = lo + (hi - lo) / 2;
            int j = upper_bound(b, b + n, x + d) - b;
            li y = h - d + sum[j] - sum[i];
            if (b[j - 1] == x + d) {
                if (y == 0) y = -1;
            } else if (j < n && x + d > a[j]) {
                y += x + d - a[j];
                if (y == 0) y = -1;
            }
            if (y >= 0) {
                lo = d + 1;
            } else {
                hi = d - 1;
            }
        }
        ans = max(ans, hi);
    }
    printf("%lld\n", ans);
    return 0;
}

