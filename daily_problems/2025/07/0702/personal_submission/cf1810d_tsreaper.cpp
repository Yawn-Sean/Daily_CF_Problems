#include <bits/stdc++.h>
using namespace std;

long long calc(long long h, int a, int b) {
    long long head = 1, tail = h;
    while (head < tail) {
        __int128 mid = (head + tail) >> 1;
        if ((a - b) * (mid - 1) + a >= h) tail = mid;
        else head = mid + 1;
    }
    return head;
}

void solve() {
    int q; scanf("%d", &q);
    long long L = 1, R = 2e18;
    while (q--) {
        int op, a, b; scanf("%d%d%d", &op, &a, &b);
        if (op == 1) {
            int n; scanf("%d", &n);
            long long l, r;
            if (n == 1) {
                l = L;
                r = min(R, 1LL * a);
            } else {
                l = max(L, 1LL * (a - b) * (n - 2) + a + 1);
                r = min(R, 1LL * (a - b) * (n - 1) + a);
            }
            if (l <= r) {
                L = l; R = r;
                printf("1");
            } else {
                printf("0");
            }
        } else {
            long long l = calc(L, a, b), r = calc(R, a, b);
            if (l == r) printf("%lld", l);
            else printf("-1");
        }
        if (q == 0) printf("\n");
        else printf(" ");
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
