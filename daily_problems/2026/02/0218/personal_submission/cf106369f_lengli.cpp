#include <bits/stdc++.h>
using namespace std;

double b1, b2, h;

double f(double x) {
    double t1 = b1 * x;
    double t2 = b2 * (h - x);
    double t3 = ((b1 + b2) * h - t1 - t2) / 2.0;

    double mx = max({t1, t2, t3});
    double mn = min({t1, t2, t3});
    return mx - mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> b1 >> b2 >> h;

    double l = 0.0, r = h;

    for (int i = 0; i < 100; i++) {
        double mid1 = (2 * l + r) / 3.0;
        double mid2 = (l + 2 * r) / 3.0;

        if (f(mid1) < f(mid2))
            r = mid2;
        else
            l = mid1;
    }

    double ans = f((l + r) / 2.0) / 2.0;

    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}
