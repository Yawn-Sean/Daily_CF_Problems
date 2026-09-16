#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> cnt(3);
    for (int i = 1; i < N; i++) {
        std::cout << "? " << 2 << " " << 1 << " " << i + 1 << std::endl;
        int o;
        std::cin >> o;
        cnt[o].push_back(i);
    }

    std::vector<int> ans(N);
    // T = 1, M = 0, F = 2;
    if (cnt[0].size() == 0) {
        ans[0] = 1;
        for (auto x : cnt[1]) {
            ans[x] = 0;
        }
        for (auto x : cnt[2]) {
            std::cout << "? " << 2 << " " << cnt[1][0] + 1 << " " << x + 1 << std::endl;
            int o;
            std::cin >> o;
            if (o == 1) {
                ans[x] = 1;
            } else {
                ans[x] = 2;
            }
        }
    } else if (cnt[2].size() == 0) {
        ans[0] = 0;
        for (auto x : cnt[1]) {
            ans[x] = 1;
        }
        for (auto x : cnt[0]) {
            std::cout << "? " << 2 << " " << cnt[1][0] + 1 << " " << x + 1 << std::endl;
            int o;
            std::cin >> o;
            if (o == 2) {
                ans[x] = 2;
            } else {
                ans[x] = 0;
            }
        }
    } else {
        ans[0] = 2;
        for (auto x : cnt[2]) {
            ans[x] = 1;
        }
        for (auto x : cnt[0]) {
            std::cout << "? " << 2 << " " << cnt[2][0] + 1 << " " << x + 1 << std::endl;
            int o;
            std::cin >> o;
            if (o == 2) {
                ans[x] = 2;
            } else {
                ans[x] = 0;
            }
        }
    }

    std::cout << "! ";
    for (int i = 0; i < N; i++) {
        if (ans[i] == 1) {
            std::cout << 'T';
        } else if (ans[i] == 0) {
            std::cout << 'F';
        } else {
            std::cout << 'M';
        }
    }
    std::cout << std::endl;

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
