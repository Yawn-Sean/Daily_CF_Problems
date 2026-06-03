#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
using ld = long double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    cin >> n;
    vector<ld> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    vector<ld> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    auto check = [&](ld mid) -> bool {
        ld pre = mid;
        for (int i = n; i >= 1; i--) {
            pre = p[i] * min(d[i], pre + 1) + (1 - p[i]) * (pre + 1);
        }
        return pre - mid >= 0;
    };

    ld l = 0, r = 1e9;
    for (int i = 1; i <= 100; i++) {
        ld mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(12) << (l + r) / 2;
    return 0;
}