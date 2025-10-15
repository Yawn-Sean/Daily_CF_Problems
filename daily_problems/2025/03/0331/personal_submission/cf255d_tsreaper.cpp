#include <bits/stdc++.h>
using namespace std;

int n, x, y, c;

long long calc(int r, int c, int v) {
    long long last = v + r - 1;
    if (last <= c) return 1LL * (v + last) * r / 2;
    else {
        int rem = r - (c - v + 1);
        return 1LL * (v + c) * (r - rem) / 2 + 1LL * rem * c;
    }
}

long long calc(int tim) {
    long long ret = 1;

    if (x - tim >= 1) {
        ret += tim;
        ret += calc(tim, min(tim, y - 1), 0);
        ret += calc(tim, min(tim, n - y), 0);
    } else {
        ret += x - 1;
        ret += calc(x - 1, min(tim, y - 1), min(tim - (x - 1), y - 1));
        ret += calc(x - 1, min(tim, n - y), min(tim - (x - 1), n - y));
    }

    if (x + tim <= n) {
        ret += tim;
        ret += calc(tim, min(tim, y - 1), 0);
        ret += calc(tim, min(tim, n - y), 0);
    } else {
        ret += n - x;
        ret += calc(n - x, min(tim, y - 1), min(tim - (n - x), y - 1));
        ret += calc(n - x, min(tim, n - y), min(tim - (n - x), n - y));
    }

    ret += min(tim, y - 1);
    ret += min(tim, n - y);

    return ret;
}

int main() {
    scanf("%d%d%d%d", &n, &x, &y, &c);
    long long head = 0, tail = 2e9;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (calc(mid) >= c) tail = mid;
        else head = mid + 1;
    }
    printf("%lld\n", head);
    return 0;
}
