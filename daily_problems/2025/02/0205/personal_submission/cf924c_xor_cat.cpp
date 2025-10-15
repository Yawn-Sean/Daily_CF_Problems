#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> m(n);
    for (int i = 0; i < n; i++) {
        std::cin >> m[i];
    }

    i64 ans = 0;
    std::vector<int> f(n);
    f[n - 1] = m[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        f[i] = std::max(f[i + 1] - 1, m[i]);
    }
    for (int i = 1; i < n; i++) {
        f[i] = std::max(f[i - 1], f[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += f[i] - m[i];
    }

    std::cout << ans << "\n";

    return 0;
}
