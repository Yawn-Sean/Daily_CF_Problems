#include <bits/stdc++.h>
using namespace std;

int __FAST_IO__ = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

const double pi = acos(-1);
void solveC() {
    int n, x, y;
    cin >> n;
    vector<double> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pos[i] = atan2(y, x) * 180 / pi;
    }
    sort(pos.begin(), pos.end());
    double ans = pos.back() - pos[0];
    for (int i = 1; i < n; i++) {
        ans = min(ans, 360 - pos[i] + pos[i-1]);
    }
    cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solveC();
    }

    return 0;
}
