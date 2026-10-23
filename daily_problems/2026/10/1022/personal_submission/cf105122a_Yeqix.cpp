#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
i64 rand(i64 l, i64 r) {
    uniform_int_distribution<i64> dist(l, r);
    return dist(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 k, n;
    cin >> k >> n;
    i64 up = k * (k + 1) / 2;

    for (int i = 1; i <= n; i++) {
        i64 v = rand(1, up);
        i64 l = 1, r = k;
        while (l <= r) {
            i64 mid = (l + r) >> 1;
            if ((k * 2 - mid + 1) * mid / 2 >= v) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << l << " " << l + (k * 2 - l + 1) * l / 2 - v << "\n";
    }
    return 0;
}