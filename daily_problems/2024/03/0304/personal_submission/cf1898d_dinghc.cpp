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
        int64 mx_a = 0, mi_b = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
            ans += b[i] - a[i];
            mx_a = max(mx_a, static_cast<int64>(a[i]));
            mi_b = min(mi_b, static_cast<int64>(b[i]));
        }

        if (mx_a > mi_b) ans += 2 * (mx_a - mi_b);

        cout << ans << endl;
    }
    return 0;
}