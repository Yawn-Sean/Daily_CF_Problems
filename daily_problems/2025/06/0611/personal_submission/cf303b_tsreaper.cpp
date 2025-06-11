#include <bits/stdc++.h>
using namespace std;

int n, m, p, q, a, b;

double calc(int x, int len, int w) {
    double mid = x + len / 2.0;
    return abs(w - mid);
}

int gao(int l, int r, int len, int w) {
    int head = l, tail = r;
    while (tail - head > 5) {
        int mid1 = head + (tail - head) / 3;
        int mid2 = head + (tail - head) / 3 * 2;
        if (calc(mid1, len, w) > calc(mid2, len, w)) head = mid1;
        else tail = mid2;
    }

    int ret = head;
    double best = calc(head, len, w);
    for (int i = head + 1; i <= tail; i++) {
        double t = calc(i, len, w);
        if (t < best) ret = i, best = t;
    }
    return ret;
}

int main() {
    scanf("%d%d%d%d%d%d", &n, &m, &p, &q, &a, &b);
    int g = gcd(a, b);
    a /= g; b /= g;

    int head = 1, tail = 1e9;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (1LL * a * mid <= n && 1LL * b * mid <= m) head = mid;
        else tail = mid - 1;
    }

    int u = a * head, v = b * head;
    int xl = max(0, p - u), xr = min(n - u, p);
    int yl = max(0, q - v), yr = min(m - v, q);
    int x = gao(xl, xr, u, p), y = gao(yl, yr, v, q);
    printf("%d %d %d %d\n", x, y, x + u, y + v);
    return 0;
}
