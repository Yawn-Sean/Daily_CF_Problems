#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int h, n;
    std::cin >> h >> n;

    std::vector<int> p(n + 1);
    p[n] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (p[i] - p[i + 1] > 1) {
            ans++;
        } else {
            i++;
        }
    }
    std::cout << ans << "\n";
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
