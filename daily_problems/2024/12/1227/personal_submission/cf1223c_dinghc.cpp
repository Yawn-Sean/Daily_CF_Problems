#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int64 mod = 1'000'000'007;
constexpr int N = 200'000;
int p[N];
int64 sum[N + 1];

int64 calc(int m, int x, int a, int y, int b) {
    int cxy = 0, cx = 0, cy = 0;
    for (int i = 1; i <= m; i++) {
        if (i % a == 0 && i % b == 0) {
            cxy += 1;
        } else if (i % a == 0) {
            cx += 1;
        } else if (i % b == 0) {
            cy += 1;
        }
    }
    return sum[cxy] * (x + y) + (sum[cx + cxy] - sum[cxy]) * x + (sum[cx + cy + cxy] - sum[cx + cxy]) * y;
};

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            p[i] /= 100;
        }
        int x, a, y, b;
        scanf("%d%d%d%d", &x, &a, &y, &b);
        int64 k;
        scanf("%lld", &k);
        sort(p, p + n, greater<int>());
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + p[i - 1];
        }
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (calc(mid, x, a, y, b) >= k) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        printf("%d\n", lo > n ? -1 : lo);
    }
    return 0;
}

