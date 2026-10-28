#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

void solve() {
    int n;
    cin >> n;
    set<array<int, 2>> st;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }

    auto [a, b] = *st.begin();
    auto [c, d] = *st.rbegin();
    if (!st.count({a, d}) || !st.count({c, b})) {
        cout << "NO\n";
        return;
    }

    for (const auto& [x, y] : st) {
        if (!(a <= x && x <= c && b <= y && y <= d)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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