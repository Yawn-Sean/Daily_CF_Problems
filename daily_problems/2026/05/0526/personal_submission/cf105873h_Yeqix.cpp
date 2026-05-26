#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<i64, 7>> a(n);
    for (auto& [d, p, c, lx, rx, ly, ry] : a) {
        cin >> d >> p >> c >> lx >> rx >> ly >> ry;
    }

    vector<double> ans(1 << n), time(1 << n);

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                int lst = i ^ (1 << j);
                auto [d, p, c, lx, rx, ly, ry] = a[j];

                time[i] = time[lst] + c;
                double D = ans[lst];
                if (time[i] <= d) {
                    D += p;
                    if (time[i] <= ly) {
                        D += 1.0 * (lx + rx) / 2;
                    } else if (time[i] <= ry) {
                        D += 1.0 * (lx + rx) / 2 * (ry - time[i]) / (ry - ly);
                    }
                }
                ans[i] = max(ans[i], D);
            }
        }
    }
    cout << fixed << setprecision(12) << ans[(1 << n) - 1];
    return 0;
}