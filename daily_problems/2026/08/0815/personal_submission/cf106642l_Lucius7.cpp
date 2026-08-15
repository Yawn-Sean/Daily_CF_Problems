#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n * 2);
    for (int i = 0; i < n * 2; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> stk;
    std::vector<bool> vis(2 * n);
    std::pair<int, int> u{-1, -1};
    for (int i = 0; i < 2 * n; i++) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            stk.push_back(a[i]);
        } else {
            bool ok = false;
            if (stk.back() != a[i]) {
                u = {a[i], stk.back()};
                ok = true;
                break;     
            }
            if (ok) {
                break;
            }
            stk.pop_back();
        }
    }

    if (u == std::pair{-1, -1}) {
        std::cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            std::cout << i << " \n"[i == n];
        }
        return;
    }

    // std::cout << u.first << " " << u.second << "\n";
    std::vector<int> ans;
    auto check = [&](int x) {
        stk.clear();
        std::fill(vis.begin(), vis.end(), false);
        for (int i = 0; i < 2 * n; i++) {
            if (a[i] == x) {
                continue;
            }
            if (!vis[a[i]]) {
                vis[a[i]] = true;
                stk.push_back(a[i]);
            } else {
                if (stk.back() != a[i]) {
                    return;
                }
                stk.pop_back();
            }
        }
        ans.push_back(x);
    };
     
    check(u.first);
    check(u.second);



    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] + 1 << " \n"[i == ans.size() - 1];
    }


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
