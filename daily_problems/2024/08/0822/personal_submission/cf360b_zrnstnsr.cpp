#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) r = max(r, a[i] - a[i-1]);
    }
    auto check = [&](int v) -> int {
        int res = n - 1;
        vector<int> d(n);
        for (int i = 1; i < n; ++i) {
            d[i] = i;
            for (int j = i - 1; j >= 0; --j) if (abs(a[i] - a[j]) <= v * (i - j)) d[i] = min(d[i], d[j] + i - j - 1);
            res = min(res, d[i] + n - i - 1);
        }
        return res;
    };
    while (l < r) {
        int mid = l + (r - l) / 2;
        // cout << "check " << mid << " = " << check(mid) << '\n';
        if (check(mid) > k) l = mid + 1;
        else r = mid;
    }
    cout << l << '\n';
}


int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
