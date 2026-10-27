#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1), pa(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pa[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    auto check = [&](int mid) -> bool {
        int st = 0;
        for (int i = 1; i <= m; i++) {
            if (b[i] <= mid) {
                if (pa[b[i]] > st) {
                    st = pa[b[i]];
                } else {
                    return 0;
                }
            }
        }
        return 1;
    };

    int l = 1, r = min(n, m);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << n + m - r * 2 << "\n";
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