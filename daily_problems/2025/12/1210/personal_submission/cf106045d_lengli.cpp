#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    cout.setf(ios::fixed);
    cout << setprecision(10);

    while (t--) {
        double r, l, theta;
        cin >> r >> l >> theta;

        theta = theta / 180.0 * acos(-1.0);
        double w = 2.0 * r * sin(theta / 2.0);
        double ans = sqrt(l * l - w * w);

        cout << ans << '\n';
    }
    return 0;
}
