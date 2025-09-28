#include <bits/stdc++.h>
using namespace std;
typedef long double db;

int main() {
    int n, r; scanf("%d%d", &n, &r);
    db ans = 0;
    while (n--) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        db d = 1.0 * abs(c) / sqrt(a * a + b * b);
        if (d >= r) continue;
        db theta = acos(d / r);
        db area = theta * r * r - d * sqrt(r * r - d * d);
        db tmp = area / (acos(-1) * r * r);
        ans = max(ans, tmp);
    }
    printf("%.12Lf %.12Lf\n", ans, 1 - ans);
    return 0;
}
