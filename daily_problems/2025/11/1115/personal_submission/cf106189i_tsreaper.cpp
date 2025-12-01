#include <bits/stdc++.h>
using namespace std;

long long n;
int X, Y, W, H;

int main() {
    scanf("%lld%d%d%d%d", &n, &X, &Y, &W, &H);

    int g = 0;
    for (int i = 0; 1LL * i * i <= n; i++) {
        long long t = n - 1LL * i * i;
        int s = sqrt(t);
        if (i <= s && 1LL * i * i + 1LL * s * s == n) g = gcd(g, gcd(i, s));
    }
    int G = g * 2;

    if (g == 0) {
        if (X <= 0 && 0 <= X + W && Y <= 0 && 0 <= Y + H) printf("1\n");
        else printf("0\n");
        return 0;
    }

    auto gao1 = [&](int x) {
        x -= g;
        if (x < 0) return 0;
        return x / G + 1;
    };

    auto gao2 = [&](int x) {
        if (x < 0) return 0;
        return x / G + 1;
    };

    X = (X % G + G) % G;
    Y = (Y % G + G) % G;
    long long t = 1LL * (gao1(X + W) - gao1(X - 1)) * (gao1(Y + H) - gao1(Y - 1));
    t += 1LL * (gao2(X + W) - gao2(X - 1)) * (gao2(Y + H) - gao2(Y - 1));
    printf("%lld\n", t);
    return 0;
}
