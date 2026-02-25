#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double y, x, r;
    cin >> y >> x >> r;

    x = abs(x);

    if (x * x * y * y > r * r * (x * x + y * y)) {
        cout << -1 << "\n";
    }
    else if (r >= x) {
        cout << 0 << "\n";
    }
    else {
        long double angle = (asin(y / hypot(x, y) / r * x) 
                       - atan2(y, x)) / 3.14159265358979323846 * 180.0;
        cout << fixed << setprecision(10) << angle << "\n";
    }

    return 0;
}
