#include <bits/stdc++.h>
using namespace std;

double power(double a, int b) {
    double y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y *= a;
        a *= a;
    }
    return y;
}

int main() {
    int m, n; scanf("%d%d", &m, &n);
    double ans = 0;
    for (int i = 1; i <= m; i++) {
        double t = power(1.0 * i / m, n) - power(1.0 * (i - 1) / m, n);
        ans += t * i;
    }
    printf("%.9f\n", ans);
    return 0;
}
