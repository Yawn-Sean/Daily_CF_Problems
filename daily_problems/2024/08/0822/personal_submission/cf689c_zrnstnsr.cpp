#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

ll exp3[400010];

void solve() {
    ll m;
    cin >> m;
    auto check = [&](ll n) -> ll {
        ll res = 0;
        for (int i = 2; exp3[i] <= n; ++i) res += n / exp3[i];
        return res;
    };
    ll l = 0, r = m * 8;
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (check(mid) < m) l = mid + 1;
        else r = mid;
    }
    if (check(l) != m) cout << "-1\n";
    else cout << l << '\n';
}


int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    for (int i = 1; i <= 400000; ++i) {
        exp3[i] = 1LL * i * i * i;
    }
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
