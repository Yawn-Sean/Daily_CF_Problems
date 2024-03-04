#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto& ai : a) {
            cin >> ai;
        }
        for (auto& bi : b) {
            cin >> bi;
        }

        int64 ans = 0LL;
        pair<int64, int> mx {0, -1}, mi {INT_MAX, -1};
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
            ans += b[i] - a[i];
            mx = max(mx, pair<int64, int>{static_cast<int64>(a[i]), i});
            mi = min(mi, pair<int64, int>{static_cast<int64>(b[i]), i});
        }

        auto& [mx_a, i] = mx;
        auto& [mi_b, j] = mi;
        if (i != j && mx_a > mi_b) ans += 2 * (mx_a - mi_b);

        cout << ans << endl;
    }
    return 0;
}