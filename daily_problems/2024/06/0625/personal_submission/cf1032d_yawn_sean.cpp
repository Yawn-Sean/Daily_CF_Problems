#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    double a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;

    double ans = 0.0 + fabs(x1 - x2) + fabs(y1 - y2);

    function<vector<pair<double, double>>(int, int)> find = [&] (int x, int y) {
        vector<pair<double, double>> ans;
        if (a) ans.push_back({-(b * y + c) / a, y});
        if (b) ans.push_back({x, -(a * x + c) / b});
        return ans;
    };

    function<double(pair<double, double>, pair<double, double>)> d = [&] (pair<double, double> x, pair<double, double> y) {
        return powf(powf(x.first - y.first, 2) + powf(x.second - y.second, 2), 0.5);
    };

    pair<double, double> p1 = {x1, y1};
    pair<double, double> p2 = {x2, y2};

    for (auto &f1: find(x1, y1))
        for (auto &f2: find(x2, y2))
            ans = min(ans, d(p1, f1) + d(f1, f2) + d(f2, p2));

    cout << setprecision(12) << ans << '\n';

    return 0;
}