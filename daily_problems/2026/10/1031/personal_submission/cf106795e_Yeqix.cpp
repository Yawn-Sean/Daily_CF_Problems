#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, r;
    cin >> n >> r;
    i64 mx = 0;
    vector<array<i64, 2>> f(n);
    for (auto& [t, c] : f) {
        cin >> t >> c;
        mx = max(mx, c);
    }

    rgs::sort(f);

    i64 g = 0;
    for (int i = 1; i < n; i++) {
        i64 lst = f[i - 1][1] + (f[i][0] - f[i - 1][0]) * r - f[i][1];
        if (lst < 0) {
            cout << -1;
            return 0;
        }
        g = __gcd(g, lst);
    }

    if (g == 0) {
        cout << mx + 1;
    } else {
        if (g <= mx) {
            cout << "-1";
        } else {
            i64 ans = 1e16;
            for (i64 i = 1; i * i <= g; i++) {
                if (g % i == 0) {
                    if (i > mx) {
                        ans = min(ans, i);
                    }
                    if (g / i > mx) {
                        ans = min(ans, g / i);
                    }
                }
            }

            cout << ans;
        }
    }
    return 0;
}