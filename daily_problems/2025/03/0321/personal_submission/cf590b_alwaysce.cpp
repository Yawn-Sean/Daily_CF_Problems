#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x1,y1,x2,y2,vm,vx,vy,wx,wy;
    long double t;
    cin >> x1 >> y1 >> x2 >> y2 >> vm >> t >> vx >> vy >> wx >> wy;

    x2 -= x1; y2 -= y1;
    long double l = 0, r = 1e9;

    for (int i = 0; i < 120; i++) {
        long double mid = (l + r) / 2;
        long double x = x2, y = y2;
        x -= min(mid, t) * vx;
        y -= min(mid, t) * vy;
        x -= (mid - min(mid, t)) * wx;
        y -= (mid - min(mid, t)) * wy;

        if (x * x + y * y <= vm * vm * mid * mid) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(20) << (l + r) / 2;
    return 0;
}
