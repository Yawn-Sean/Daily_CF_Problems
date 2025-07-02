#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    auto dist = [&](int i, int j) {
        return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]));
    };
    double ans = 1E9;

    for (int i = 1; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ans = min(ans, dist(0, i) + dist(i, j) + dist(j, 0));
        }
    }
    ans /= 2;
    cout << fixed << setprecision(10) << ans << "\n";

    return 0;
}
