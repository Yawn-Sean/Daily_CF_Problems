#include <bits/stdc++.h>

using namespace std;

long double cal(long double sx, long double sy, long double tx, long double ty) {
    return fabs(sx - tx) + fabs(sy - ty);
}

long double cal2(long double sx, long double sy, long double tx, long double ty) {
    return sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));
}

int main() {
    long double a, b, c;
    cin >> a >> b >> c;
    // cout << fixed << setprecision(12) << c << endl;
    long double sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    long double ans = fabs(sx - tx) + fabs(sy - ty);
    if (fabs(a) <= 1e-6 || fabs(b) <= 1e-6) cout << fixed << setprecision(12) << ans << endl;
    else {
        vector<pair<long double, long double>> v;
        v.push_back({sx, (-1.0 * c - a * sx) / b});
        v.push_back({tx, (-1.0 * c - a * tx) / b});
        v.push_back({(-1.0 * c - b * sy) / a, sy});
        v.push_back({(-1.0 * c - b * ty) / a, ty});
        // cout << v.size() << endl;
        // for (int i = 0; i < v.size(); i ++) {
        //     cout << v[i].first << ' ' << v[i].second << endl;
        // }
        for (int i = 0; i < v.size(); i ++) {
            for (int j = 0; j < v.size(); j ++) {
                ans = min(ans, cal(sx, sy, v[i].first, v[i].second) + cal2(v[i].first, v[i].second, v[j].first, v[j].second) + cal(v[j].first, v[j].second, tx, ty));
            }
        }
        cout << fixed << setprecision(12) << ans << endl;
    }

    return 0;
}
