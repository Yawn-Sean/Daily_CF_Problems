#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    int a, b, m, vx, vy, vz; scanf("%d%d%d%d%d%d", &a, &b, &m, &vx, &vy, &vz);
    double t = -1.0 * m / vy;
    
    double x = t * vx;
    bool sgn;
    if (x > 0) sgn = false;
    else sgn = true, x = -x;

    x = x - floor(x / (a * 2)) * (a * 2);
    if (x < a / 2.0) {
        x += a / 2.0;
    } else if (x > a * 3 / 2.0) {
        x -= a * 3 / 2.0;
    } else {
        x = a - (x - a / 2.0);
    }
    if (sgn) x = a - x;

    double z = t * vz;
    z = z - floor(z / (b * 2)) * (b * 2);
    if (z > b) z = b - (z - b);

    printf("%.12f %.12f\n", x, z);
    return 0;
}
