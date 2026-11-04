#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int inf = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (auto& [x, y, mask] : a) {
        cin >> x >> y;
        if (x < 0) {
            mask |= 1;
        }
        if (x > 0) {
            mask |= 2;
        }
        if (y > 0) {
            mask |= 4;
        }
        if (y < 0) {
            mask |= 8;
        }
    }

    int res = 4, sum = 15;
    for (int mask = 0; mask < 16; mask++) {
        if (__builtin_popcount(mask) >= res) {
            continue;
        }

        int can = 1;
        for (const auto& [x, y, msk] : a) {
            if ((msk & mask) == 0) {
                can = 0;
                break;
            }
        }

        if (can) {
            res = __builtin_popcount(mask);
            sum = mask;
        }
    }

    vector<array<int, 5>> ans(4, {inf, -inf, inf, -inf});
    for (const auto& [x, y, mask] : a) {
        for (int j = 0; j < 4; j++) {
            if ((sum & mask & (1 << j))) {
                ans[j][4] = 1;
                ans[j][0] = min(ans[j][0], x);
                ans[j][1] = max(ans[j][1], x);
                ans[j][2] = min(ans[j][2], y);
                ans[j][3] = max(ans[j][3], y);
                break;
            }
        }
    }

    cout << res << "\n";
    cout << fixed << setprecision(1);
    for (const auto& [a, b, c, d, use] : ans) {
        if (!use) {
            continue;
        }

        cout << (a - 0.1) << " " << c - 0.1 << " " << (a - 0.1) << " " << (d + 0.1) << " " << b + 0.1 << " " << (c - 0.1) << " " << b + 0.1 << " " << (d + 0.1) << "\n";
    }
    return 0;
}