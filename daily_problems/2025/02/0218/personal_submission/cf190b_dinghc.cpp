#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, r1;
    scanf("%d%d%d", &x1, &y1, &r1);
    int x2, y2, r2;
    scanf("%d%d%d", &x2, &y2, &r2);
    int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (r1 < r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    double ans = 0;
    if ((r1 - r2) * (r1 - r2) > d) {
        ans = (r1 - sqrt(d) - r2) / 2;
    } else if ((r1 + r2) * (r1 + r2) < d) {
        ans = (sqrt(d) - r1 - r2) / 2;
    } else {
        ans = 0;
    }
    printf("%.10lf\n", ans);
    return 0;
}

