#include <bits/stdc++.h>
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
 
using i128 = __int128;
using u128 = unsigned __int128;

i64 isqrt(i64 x) {
    i64 l = 0, r = x;
    while (l < r) {
        i64 mid = l + (r - l + 1) / 2;
        if (mid <= x / mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> x(m, 0), y(m, 0);
    for (int i = 0; i < m; ++i) {
        std::cin >> x[i] >> y[i];
    }

    std::vector<std::map<std::pair<i64, i64>, int>> f(n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (y[j] != y[i] && (y[j] * x[i] - y[i] * x[j]) % (y[j] - y[i]) == 0) {
                i64 dx = x[j] - x[i];
                i64 dy = y[j] - y[i];
                if (dy < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                i64 g = std::gcd(dy, dx);
                dx /= g;
                dy /= g;
                i64 px = (y[j] * x[i] - y[i] * x[j]) / (y[j] - y[i]);
                if (px >= 1 && px <= n) {
                    ++f[px][{dx, dy}];
                }
            }
        }
    }

    std::vector<int> ans(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        for (auto &[k, t] : f[i]) {
            ans[i] = std::max(ans[i], int(1 + isqrt(1 + 8 * t)) / 2);
        }
    }

    std::cout << std::accumulate(ans.begin() + 1, ans.end(), 0) << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
