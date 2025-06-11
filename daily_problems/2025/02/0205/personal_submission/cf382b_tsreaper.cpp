#include <bits/stdc++.h>
#define MAXW 1000
using namespace std;
typedef pair<long long, long long> pll;

pll f[MAXW + 5];

int main() {
    int a, b, w, x, c; scanf("%d%d%d%d%d", &a, &b, &w, &x, &c);
    if (c <= a) { printf("0\n"); return 0; }
    c -= a;
    long long ans = c;

    for (int i = 0; i <= w; i++) f[i] = {-1, -1};
    while (f[b].first < 0) {
        f[b] = {ans, c};
        c -= b / x;
        if (c <= 0) { printf("%lld\n", ans); return 0; }
        ans++;
        b = w - (x - b % x);
    }

    long long det = f[b].second - c, steps = c / det;
    if (c % det == 0) steps--;
    ans += steps * (ans - f[b].first);
    c -= steps * det;

    while (true) {
        c -= b / x;
        if (c <= 0) { printf("%lld\n", ans); return 0; }
        ans++;
        b = w - (x - b % x);
    }
}
