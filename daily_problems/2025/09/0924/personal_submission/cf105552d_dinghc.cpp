#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    double mn_dist = r;
    for (int i = 0, a, b, c; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        double x1, y1;
        if (a != 0) {
            x1 = -1.0 * c / a;
            y1 = 0;
        } else {
            x1 = 0;
            y1 = -1.0 * c / b;
        }
        double x2, y2;
        if (a == 0) {
            x2 = 1.0;
            y2 = 0;
        } else if (b == 0) {
            x2 = 0;
            y2 = 1.0;
        } else {
            x2 = 1.0 * b / a;
            y2 = 1.0;
            double d = sqrt(x2 * x2 + y2 * y2);
            x2 /= d;
            y2 /= d;
        }
        double dot = x1 * x2 + y1 * y2;
        mn_dist = min(mn_dist, sqrt(x1 * x1 + y1 * y1 - dot * dot));
    }
    double theta = acos(mn_dist / r) * 2;
    double p = (theta / 2 - sin(theta) / 2) / acos(-1);
    printf("%.9f %.9f\n", p, 1 - p);
    return 0;
}

