#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
    i64 n, t;
    cin >> n >> t;
    i64 pre = 0, v = 0;
    while ((t & 1) == v) {
        if (v) {
            pre += n / 2;
            v ^= (n & 1), n = (n + 1) / 2, t = (t + 1) / 2;
        } else {
            pre += (n + 1) / 2;
            v ^= (n & 1), n >>= 1, t >>= 1;
        }
    }

    cout << pre + (t + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}