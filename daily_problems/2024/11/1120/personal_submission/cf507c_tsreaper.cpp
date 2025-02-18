#include <bits/stdc++.h>
using namespace std;

int h;
long long n, ans;

void gao(long long l, long long r, int dir) {
    if (l == r) { printf("%lld\n", ans); exit(0); }
    long long mid = (l + r) >> 1;
    if (dir == 0) {
        if (n <= mid) ans++, gao(l, mid, 1);
        else ans += (mid - l + 1) * 2, gao(mid + 1, r, 0);
    } else {
        if (n > mid) ans++, gao(mid + 1, r, 0);
        else ans += (mid - l + 1) * 2, gao(l, mid, 1);
    }
}

int main() {
    scanf("%d%lld", &h, &n);
    gao(1, 1LL << h, 0);
    return 0;
}
