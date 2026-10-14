#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::map<std::pair<int, int>, bool> blocked;
    auto ask = [&](int l, int r) {
        std::cout << "? " << l + 1 << " " << r + 1 << std::endl;
        int x, u, v;
        std::cin >> x >> u >> v;
        u--, v--;
        blocked[{u, v}] = true;
        return x;
    };

    std::vector<int> a(n), pre(n + 1);
    for (int r = 0; r < n; r++) {
        for (int l = r; l >= 0; l--) {
            if (!blocked[{l, r}]) {
                a[r] = ask(l, r) + pre[l] - pre[r];
                pre[r + 1] = pre[r] + a[r];
                break;
            }
        }
        
    }

    std::cout << "! ";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];    
    }
    std::cout.flush();
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
