#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

bool check(double m, vector<int>& x, vector<int>& v) {
    double l = -1e18, r = 1e18;
    for (int i = 0; i < x.size(); i++) {
        l = max(l, 1.0 * x[i] - 1.0 * v[i] * m);
        r = min(r, 1.0 * x[i] + 1.0 * v[i] * m);
    }
    return l <= r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    int n;
    cin >> n;
    vector<int> x(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    double l = 0, r = 1e9;
    while (abs(l - r) > 1e-7) {
        double m = (l + r) / 2;
        if (check(m, x, v)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l << endl;
    return 0;
}
