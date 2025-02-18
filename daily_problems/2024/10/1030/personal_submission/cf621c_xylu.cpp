#include <bits/stdc++.h>
using namespace std;

void solveC() {
    int n, p, l, r;
    cin >> n >> p;
    vector<double> pp(n);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        pp[i] = (r / p - (l - 1) / p) / (r - l + 1.0);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        double pa = pp[i], pb = pp[(i+1)%n];
        ans += 2000 * (1 - (1 - pa) * (1 - pb));
    }
    cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
    solveC();
    return 0;
}
