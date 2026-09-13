#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> g(n - 1, std::vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
            g[i][j]--;
        }
    }

    std::vector<int> f(n);
    for (int j = 0; j < n; j++) {
        std::map<int, int> cnt;
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            cnt[g[i][j]]++;
            if (cnt[g[i][j]] == 2) {
                ok = false;
            }
        }

        if (ok) {
            for (int i = 0; i < n; i++) {
                if (!cnt.contains(i)) {
                    f[i]++;
                    break;
                }
            }
        }
    }

    int u = 1;
    for (int i = 0; i < n; i++) {
        if (f[i]) {
            u *= f[i];
            u %= P;
        }
    }

    int v = std::count(f.begin(), f.end(), 0);
    std::cout << n - v << " ";
    int res = 1;
    for (int i = 1; i <= v; i++) {
        res *= i;
        res %= P;
    }
    // std::cout << u << " " << res << "\n";

    std::cout << u * res % P << "\n";


}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
