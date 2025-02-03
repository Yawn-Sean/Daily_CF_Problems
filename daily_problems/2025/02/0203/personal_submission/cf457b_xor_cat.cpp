#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n;
    std::cin >> m >> n;

    std::vector<i64> a(m), b(n);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::ranges::sort(a);
    std::ranges::sort(b);

    i64 sa = std::reduce(a.begin(), a.end());
    i64 sb = std::reduce(b.begin(), b.end());

    i64 ans1 = sb, ans2 = sa;
    for (int i = 0; i < m - 1; i++) {
        ans1 += std::min(sb, a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        ans2 += std::min(sa, b[i]);
    }

    std::cout << std::min(ans1, ans2) << "\n";

    return 0;
}
