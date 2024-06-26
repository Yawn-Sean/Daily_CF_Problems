#include <bits/stdc++.h>
using namespace std;
double dis(double xi, double yi, double xj, double yj) {
    return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
}
int main() {
    int A, B, C, xa, ya, xb, yb;
    cin >> A >> B >> C >> xa >> ya >> xb >> yb;
    double ans = 1.0 * abs(ya - yb) + abs(xa - xb);
    double ay = ((double)1.0 * -B * ya - C) / A;
    double ax = ((double)1.0 * -A * xa - C) / B;
    double by = ((double)1.0 * -B * yb - C) / A;
    double bx = ((double)1.0 * -A * xb - C) / B;
    double d1 = 1.0 * abs((double)ay - xa) + dis(ay, ya, xb, bx) + abs((double)bx - yb);
    double d2 = 1.0 * abs((double)ay - xa) + dis(ay, ya, by, yb) + abs((double)by - xb);
    double d3 = 1.0 * abs((double)ax - ya) + dis(xa, ax, xb, bx) + abs((double)bx - yb);
    double d4 = 1.0 * abs((double)ax - ya) + dis(xa, ax, by, yb) + abs((double)by - xb);
    ans = min({ans, d1, d2, d3, d4});
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}