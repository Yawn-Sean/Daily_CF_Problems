#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n, m, k;
    cin >> n >> m >> k;
    vector<array<i64, 2>> a(n);
    for (auto& [x, y] : a) {
        cin >> x;
    }

    vector<i64> cnt(n);
    for (int i = 0; i < n; i++) {
        i64 l = 0, r = k;
        while (l <= r) {
            i64 mid = (l + r) >> 1;
            if ((k * 2 - mid + 1) * mid / 2 <= a[i][0]) {
                cnt[i] = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    i64 ans = 0;
    auto check = [&](i64 mid) -> int {
        auto p = a;
        i64 res = 0, rr = m;
        for (int i = 0; i < n; i++) {
            i64 g = min(mid, cnt[i]);
            i64 v = (k * 2 - g + 1) * g / 2;
            res += v, rr -= g, p[i][0] -= v, p[i][1] += g;
        }

        if (rr < 0) {
            return 0;
        }

        sort(p.begin(), p.end(), [&](auto x, auto y) { return min(x[0], k - x[1]) > min(y[0], k - y[1]); });

        for (int i = 0; i < n; i++) {
            if (rr > 0 && min(p[i][0], k - p[i][1])) {
                res += min(p[i][0], k - p[i][1]);
                rr--;
            }
        }

        ans = max(ans, res);
        return 1;
    };

    i64 l = 0, r = k;
    while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}