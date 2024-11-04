#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int mn = x / y;
    multiset<int> st;
    vector<pair<int, int>> vals(n);
    for (int i = 0; i < n; ++i) cin >> vals[i].first >> vals[i].second;
    ranges::sort(vals);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = st.lower_bound(vals[i].first);
        if (it != st.begin()) {
            auto r = prev(it);
            if (*r + mn >= vals[i].first) {
                ans = (ans + 1LL * (vals[i].second - *r) * y) % mod;
                st.erase(r);
                goto https;
            }
        }
        ans = (ans + x + 1LL * (vals[i].second - vals[i].first) * y) % mod;
        https://github.com/ghj123h/
        st.insert(vals[i].second);
    }
    println("{}", ans);
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
