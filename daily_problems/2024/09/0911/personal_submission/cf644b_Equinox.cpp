#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;

constexpr int N = 2E5 + 10;

void solve() {
    int n, b;

    std::cin >> n >> b;

    std::vector<i64> ans(n, -1);

    i64 ma = 0;
    std::queue<int> q;

    for (int i = 0, t, d; i < n; ++ i) {
        std::cin >> t >> d;
        if (q.size() && q.front() <= t) q.pop();
        if (q.size() > b) {
            std::cout << -1 << " \n"[i + 1 == n];
        }
        else {
            ma = std::max<i64>(ma, t) + d;
            q.push(ma);
            std::cout << ma << " \n"[i + 1 == n];
        }
    }
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