#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    double ans = 0;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        ans = max(ans, (static_cast<double>(v[a - 1]) + v[b - 1]) / c);
    }

    cout << fixed << setprecision(15) << ans << "\n";

    return 0;
}

