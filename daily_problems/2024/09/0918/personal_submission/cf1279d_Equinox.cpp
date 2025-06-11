#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

constexpr int N = 1E6;
std::vector<int> inv;
auto INIT = []{
    inv.resize(N + 1);
    inv[1] = 1;
    for(int i = 2; i <= N; i++){
        inv[i] = (1LL * P - P / i) * inv[P % i] % P;
    }
    return 0;
}();

void solve() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n);
    std::vector<int> cnt(N);
    for (int i = 0, k; i < n; ++ i) {
        std::cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; ++ j) {
            std::cin >> a[i][j];
            ++ cnt[a[i][j]];
        }
    }

    int res = 0;

    for (auto &v : a) {
        int s = 0;
        for (int x : v)
            s = (s + 1LL * cnt[x] * inv[n] % P) % P;
        res = (res + 1LL * s * inv[v.size()] % P) % P;
    }

    std::cout << 1LL * res * inv[n] % P;
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