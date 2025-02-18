#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1'000'000'007;
constexpr int inf32 = 1E9 + 7;

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;

    int ans = 0;
    std::vector<std::pair<int, int>> segs(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> segs[i].first >> segs[i].second;
        ans += ((1LL * segs[i].second - segs[i].first) * y + x) % P;
        if (ans >= P) ans -= P;
    }
    std::ranges::sort(segs);
    std::multiset<int> st;
    for (int i = 0; i < n; ++ i) {
        auto it = st.lower_bound(segs[i].first);
        if (it == st.begin()) {
            st.insert(segs[i].second);
            continue;
        }
        -- it;
        if ((1LL * segs[i].first - *it) * y < x) {
            ans += (1LL * segs[i].first - *it) * y % P;
            if (ans >= P) ans -= P;
            ans = ((ans - x) % P + P) % P;
            st.erase(it);
        }
        st.insert(segs[i].second);
    }
    std::cout << ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}