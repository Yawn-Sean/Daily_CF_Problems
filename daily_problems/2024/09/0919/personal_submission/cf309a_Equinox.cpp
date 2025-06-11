#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

/*
    第一次撞的距离
    后面再撞就是 L
    俩人加起来一共2t

    可能的结果只有 2t / l 和 2t / l + 1
    
    bound = 2t % l
*/

void solve() {
    int n, l, t;

    std::cin >> n >> l >> t;

    std::vector<int> pos(n);
    for (int i = 0; i < n; ++ i)
        std::cin >> pos[i];

    std::ranges::sort(pos);

    for (int i = 0; i < n; ++ i)
        pos.push_back(pos[i] + l);

    t *= 2;
    int r = t % l;

    double ans = 1.0 * n * (n - 1) * (t / l);

    for (int i = 0; i < n; ++ i) 
        ans += std::upper_bound(pos.begin(), pos.end(), pos[i] + r) - pos.begin() - i - 1;

    std::cout << std::setprecision(10) << ans / 4 << '\n';
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