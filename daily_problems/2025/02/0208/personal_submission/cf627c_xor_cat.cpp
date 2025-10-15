#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int d, n, m;
    std::cin >> d >> n >> m;

    std::vector<std::array<int, 2>> a(m + 2);
    a[0] = {0, 0};
    a[m + 1] = {d, 0};
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i][0] >> a[i][1];
    }
    std::ranges::sort(a);

    std::vector<int> b(m + 1);
    std::vector<int> stk{m + 1};
    for (int i = m; i >= 0; i--) {
        while (a[stk.back()][1] > a[i][1]) {
            stk.pop_back();
        } 
        b[i] = stk.back();
        stk.push_back(i);
    }
    
    i64 ans = 0, now = n;
    for (int i = 0; i <= m; i++) {
        int d = std::max<i64>(0, std::min(n, a[b[i]][0] - a[i][0]) - now);
        ans += 1LL * d * a[i][1];
        now += d - (a[i + 1][0] - a[i][0]);
        if (now < 0) {
            std::cout << -1 << "\n";
            return 0;
        }
    }

    std::cout << ans << "\n";
    
    return 0;
}
