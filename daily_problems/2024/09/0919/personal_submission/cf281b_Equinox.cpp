#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int x, y, n;
    std::cin >> x >> y >> n;

    if (y <= n) {
        std::cout << x << '/' << y;
        return;
    }

    int p = (x + y - 1) / y;

    int ansx = 0, ansy = 1;

    for (int b = 1; b <= n; ++ b) {
        int t = 1LL * b * x / y;
        for (int a = t; a < t + 2; ++ a) {
            if (abs(1LL * a * y - 1LL * x * b) * abs(1LL * ansy * y) < abs(1LL * ansx * y - 1LL * x * ansy) * abs(1LL * b * y))
                ansx = a, ansy = b;
        }
    }

    std::cout << ansx << '/' << ansy;
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