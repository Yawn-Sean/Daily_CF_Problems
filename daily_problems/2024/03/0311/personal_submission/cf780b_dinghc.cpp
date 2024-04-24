#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    cout << fixed << setprecision(12);
    int n;
    cin >> n;

    int mx_d = 1, mi_v = 1e9;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        mx_d = max(mx_d, x[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mi_v = min(mi_v, v[i]);
    }

    auto check = [&] (double sec) -> bool {
        double left = x[0] - v[0] * sec, right = x[0] + v[0] * sec;
        for (int i = 1; i < n; i++) {
            left = max(left, x[i] - v[i] * sec);
            right = min(right, x[i] + v[i] * sec);
        }
        return left <= right;
    };

    double lo = 0, hi = mx_d * 1.0 / mi_v;
    while (hi - lo > 0.000001) {
        double mid = (lo + hi) / 2.0;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << lo << "\n";
    return 0;
}
