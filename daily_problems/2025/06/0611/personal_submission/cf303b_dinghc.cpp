#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x, y, a, b;
    scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &a, &b);
    int g = gcd(a, b);
    a /= g;
    b /= g;
    int k = min(n / a, m / b);
    a *= k;
    b *= k;
    int left = x - min(x, max((a + 1) / 2, a - (n - x)));
    int bottom = y - min(y, max((b + 1) / 2, b - (m - y)));
    int right = left + a;
    int up = bottom + b;
    printf("%d %d %d %d\n", left, bottom, right, up);
    return 0;
}

