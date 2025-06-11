#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> acc(n);
    for (int i = 0; i < n; ++ i) {
        std::cin >> acc[i];;
        if (i)
            acc[i] += acc[i - 1];
    }

    for (int i = n - 2; i; -- i) {
        acc[i] = std::max(acc[i + 1], acc[i] - acc[i + 1]);
    }

    std::cout << acc[1];
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