#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    double ans = 1e10;
    // x1 - a = b - 0
    int x1 = a + b;
    int q = x1 / b;
    if (q % 2 == 1) {
        q -= 1;
    }
    if (q) ans = min(ans, static_cast<double>(x1) / q);
    // x2 - a = 0 - b
    int x2 = a - b;
    if (x2 >= 0) {
        q = x2 / b;
        if (q % 2 == 1) {
            q -= 1;
        }
        if (q) ans = min(ans, static_cast<double>(x2) / q);
    }
    if (ans >= 1e10) {
        printf("-1\n");
    } else {
        printf("%.12f\n", ans);
    }
    return 0;
}

