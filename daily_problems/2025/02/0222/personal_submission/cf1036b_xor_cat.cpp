#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    i64 n, m, k;
    std::cin >> n >> m >> k;

    if (std::max(n, m) > k) {
        std::cout << -1 << "\n";
        return;
    }
    if ((std::max(n, m) - std::min(n, m)) % 2 == 0 &&
        std::min(n, m) % 2 == k % 2) {
        std::cout << k << "\n";
        return;
    }
    if ((std::max(n, m) - std::min(n, m)) % 2 == 1) {
        std::cout << k - 1 << "\n";
        return;
    }
    if (k - std::max(n, m) % 2) {
        std::cout << k - 2 << "\n";
        return;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
