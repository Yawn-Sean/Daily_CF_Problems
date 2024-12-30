#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
    long long xa, ya, xb, yb; scanf("%lld%lld%lld%lld", &xa, &ya, &xb, &yb);

    double ans = abs(xb - xa) + abs(yb - ya);
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
        double t = 0, xc, yc, xd, yd;
        
        if (i == 0) {
            if (b == 0) continue;
            xc = xa;
            yc = (-c - a * xc) / b;
            t += abs(yc - ya);
        } else {
            if (a == 0) continue;
            yc = ya;
            xc = (-c - b * yc) / a;
            t += abs(xc - xa);
        }

        if (j == 0) {
            if (b == 0) continue;
            xd = xb;
            yd = (-c - a * xd) / b;
            t += abs(yd - yb);
        } else {
            if (a == 0) continue;
            yd = yb;
            xd = (-c - b * yd) / a;
            t += abs(xd - xb);
        }

        t += sqrt((xc - xd) * (xc - xd) + (yc - yd) * (yc - yd));
        ans = min(ans, t);
    }

    printf("%.9f\n", ans);
    return 0;
}
