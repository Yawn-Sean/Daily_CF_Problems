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
    vector<i64> a(n + 1), bit(30);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            if (a[i] >> j & 1) {
                bit[j]++;
            }
        }
    }

    i64 r = 1;
    for (int i = 1; i < n; i++) {
        r = r * i % md;
    }

    auto get = [&](i64 x) -> i64 {
        i64 ans = 0;
        for (int i = 0; i < 30; i++) {
            if (x >> i & 1) {
                ans = (ans + 1LL * (n - bit[i]) * (1LL << i) % md) % md;
            } else {
                ans = (ans + 1LL * bit[i] * (1LL << i) % md) % md;
            }
        }
        return ans;
    };

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        i64 x;
        cin >> x;
        ans = (ans + get(x)) % md;
    }

    cout << ans * r % md;
    return 0;
}