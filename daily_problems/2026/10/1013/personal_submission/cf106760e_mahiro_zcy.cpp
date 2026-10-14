
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

using i128 = __int128;
using u128 = unsigned __int128;

constexpr int inf = std::numeric_limits<int>::max();

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> h(n, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    std::vector<int> f(n, inf);
    for (int i = 0; i < n; ++i) {
        int x = std::lower_bound(f.begin(), f.end(), h[i]) - f.begin();
        f[x] = h[i];
        if (i >= 1 && h[i] < h[i - 1]) {
            f[x + 1] = std::min(f[x + 1], h[i - 1]);
        }
    }

    int ans = 0;
    while (ans < n && f[ans] != inf) {
        ++ans;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
