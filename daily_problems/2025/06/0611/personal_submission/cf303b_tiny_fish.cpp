#include <bits/stdc++.h>

using std::cin, std::cout, std::ios;

int main() {
    int n, m, x, y, a, b; cin >> n >> m >> x >> y >> a >> b;
    int g = std::gcd(a, b); a /= g, b /= g;
    int k = std::min(n / a, m / b); a *= k, b *= k;

    double mn = 1e18; int ansx = 0, ansy = 0;

    int xl = std::max(x - (a + 1) / 2, 0), xr = std::min(std::max(xl + a, x + (a + 1) / 2), n);
    int yl = std::max(y - (b + 1) / 2, 0), yr = std::min(std::max(yl + b, y + (b + 1) / 2), m);

    xl = std::min(xl, xr - a);
    yl = std::min(yl, yr - b);

    for(int i = xl; i + a <= xr; i++) {
        for(int j = yl; j + b <= yr; j++) {
            if(i <= x and x <= i + a and j <= y and y <= j + b) {
                double _x = i + a / 2.0, _y = j + b / 2.0;
                double dis = std::sqrt((x - _x) * (x - _x) + (y - _y) * (y - _y));
                if(dis < mn) {
                    mn = dis;
                    ansx = i, ansy = j;
                }
            }
        }
    }

    cout << ansx << ' ' << ansy << ' ' << ansx + a << ' ' << ansy + b << '\n';

    return 0;
}