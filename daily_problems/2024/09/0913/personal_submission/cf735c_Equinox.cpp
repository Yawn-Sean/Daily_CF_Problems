#include <bits/stdc++.h>
// #include <ranges>
 
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
 
constexpr int P = 1'000'000'007;
constexpr int inf32 = 1E9 + 7;
 
void solve() {
    i64 n;
    std::cin >> n;
 
    int res = 0;
    std::vector<i64> f(100);
    f[0] = 1, f[1] = 2, f[2] = 3, f[3] = 5;
    for (int i = 4; i < 100; ++ i) f[i] = f[i - 1] + f[i - 2];
 
    while (f[res] <= n)
        ++ res;
 
    std::cout << res - 1;
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