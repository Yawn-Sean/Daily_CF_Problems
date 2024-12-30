#include <bits/stdc++.h>
#include <ranges>
#define sc scanf
using i64 = long long;

constexpr double eps = 1e-9;

double dist(int x, int y, int a, int b) { 
    return sqrt((i64)(x - a) * (x - a) + (i64)(y - b) * (y - b)); 
}

void solve() {
    int ax, ay, bx, by, tx, ty;
    sc("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
    // std::cin >> ax >> ay >> bx >> by >> tx >> ty;

    int n;
    // std::cin >> n;
    sc("%d", &n);

    std::vector<double> dst(n), pre(n + 1), suf(n + 1);

    double sum = 0;
    
    for (int i = 0, x, y; i < n; ++ i) {
        // std::cin >> x >> y;
        sc("%d%d", &x, &y);
        double d = dist(tx, ty, x, y);
        sum += d * 2;

        double db = dist(bx, by, x, y);
        pre[i + 1] = suf[i] = db - d;
        dst[i] = dist(ax, ay, x, y) - d;
    }
    pre[0] = suf[n] = 1e18 + 5;

    for (int i = 0; i < n; ++ i)
        pre[i + 1] = std::min(pre[i + 1], pre[i]);
    for (int i = n - 1; ~i; -- i)
        suf[i] = std::min(suf[i + 1], suf[i]);

    double res = sum + suf[0];

    for (int i = 0; i < n; ++ i) {
        res = std::min(res, sum + dst[i] + std::min({ 0.0, pre[i], suf[i + 1] }) );
    }

    // std::cout << std::setprecision(15) << res;
    printf("%.12lf", res);
}

int main() {
    #ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    // std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
