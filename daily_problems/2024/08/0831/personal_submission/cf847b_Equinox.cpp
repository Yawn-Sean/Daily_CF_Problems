#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1'000'000'007;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++ i) std::cin >> a[i];

    std::vector<std::vector<int>> lis;
    
    for (int i = 0; i < n; ++ i) {
        int lo = 0, hi = lis.size();
        while (lo < hi) {
            int x = lo + hi >> 1;
            if (lis[x].back() < a[i]) hi = x;
            else lo = x + 1;
        }
        if (hi == lis.size()) lis.push_back({a[i]});
        else lis[hi].push_back(a[i]);
    }
    
    for (auto &v : lis)
        for (int i = 0; i < v.size(); ++ i)
            std::cout << v[i] << " \n"[i + 1 == v.size()];
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