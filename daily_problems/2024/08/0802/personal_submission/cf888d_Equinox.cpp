#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

constexpr int N = 1005;
i64 C[N][N];
auto init = [] {
    C[0][0] = 1;
    for (int i = 1; i <= 1000; ++ i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < 1000; ++ j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    return 0;
}();

i64 Comb(int n, int m) {
    return C[n][m];
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::array<int, 5> f{ 0, 0, 1, 2, 9 };
    i64 res = 1;
    for (int i = 1; i <= k; ++ i) {
        res += 1LL * Comb(n, i) * f[i];
    }
    std::cout << res;
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}