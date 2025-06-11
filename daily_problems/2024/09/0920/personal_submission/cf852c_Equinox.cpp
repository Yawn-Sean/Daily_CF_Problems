#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), id(n);
    for (int i = 0; i < n; ++ i) std::cin >> a[id[i] = i];

    std::ranges::sort(id, [&](int x, int y) -> bool {
        return a[x] + a[(x + 1) % n] < a[y] + a[(y + 1) % n];
    });


    std::vector<int> ans(n);
    for (int i = 0; i < n; ++ i)
        ans[id[i]] = i;

    for (int i = 0; i < n; ++ i)
        std::cout << ans[i] << " \n"[i + 1 == n];
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