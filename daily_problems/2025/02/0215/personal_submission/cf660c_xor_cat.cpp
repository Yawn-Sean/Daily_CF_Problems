#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (k == 0) {
        int now = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                now++;
            } else {
                chmax(ans, now);
                now = 0;
            }
        }
        chmax(ans, now);
        std::cout << ans << "\n";
        for (auto &x : a) {
            std::cout << x << " ";
        }
        return 0;
    }

    int l = 0, r = 0, p = 0;
    int cnt = 0, ans = -1;
    while (l < n) {
        while (r < n && (cnt + (a[r] == 0 ? 1 : 0)) <= k) {
            cnt += (a[r] == 0);
            r++;
        }
        if (chmax(ans, r - l)) {
            p = l;
        }
        cnt -= (a[l] == 0);
        l++;
    }

    std::cout << ans << "\n";
    for (int i = 0; i < ans; i++) {
        a[p + i] = 1;
    }

    for (auto &x : a) {
        std::cout << x << " ";
    }

    return 0;
}
