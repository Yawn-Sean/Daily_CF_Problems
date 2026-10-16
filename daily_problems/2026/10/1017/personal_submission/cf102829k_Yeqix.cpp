#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int md = (int)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<i64, 2>> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i][0] >> f[i][1];
    }

    vector<i64> pw2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pw2[i] = pw2[i - 1] * 2 % md;
    }

    auto cross = [&](int i, int j, int k) -> i64 {
        auto [a, b] = f[i];
        auto [c, d] = f[j];
        auto [e, g] = f[k];

        return (c - a) * (g - b) - (d - b) * (e - a);
    };

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            i64 L = 0;
            for (int k = 1; k <= n; k++) {
                if (k != i && k != j && cross(i, k, j) < 0) {
                    L++;
                }
            }

            ans = (ans + (pw2[L] + pw2[n - 2 - L]) % md) % md;
        }
    }

    cout << ans + n;
    return 0;
}