#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1'000'000'007;

void solve() {
    int n;
    std::cin >> n;

    std::vector<i64> f(10, -inf64), nf(10, -inf64);
    f[0] = 0;

    while (n --) {
        int m;
        std::cin >> m;

        std::vector<int> a[4];

        for (int i = 0, c, d; i < m; ++ i) {
            std::cin >> c >> d;
            a[c].push_back(d);
        }

        for (int i = 1; i < 4; ++ i)
            std::ranges::sort(a[i], std::greater<i64>());

        for (int i1 = 0; i1 <= 3 && i1 <= a[1].size(); ++ i1) {
            for (int i2 = 0; i1 + i2 * 2 <= 3 && i2 <= a[2].size(); ++ i2) {
                for (int i3 = 0; i1 + i2 * 2 + i3 * 3 <= 3 && i3 <= a[3].size(); ++ i3) {
                    i64 s = 0;
                    int ma = 0;

                    for (int i = 0; i < i1; ++ i)
                        s += a[1][i], ma = std::max(ma, a[1][i]);

                    for (int i = 0; i < i2; ++ i)
                        s += a[2][i], ma = std::max(ma, a[2][i]);

                    for (int i = 0; i < i3; ++ i)
                        s += a[3][i], ma = std::max(ma, a[3][i]);

                    for (int i = 0; i < 10; ++ i) {
                        int r = i + i1 + i2 + i3;
                        i64 v = s + f[i];
                        if (r >= 10)
                            r -= 10, v += ma;
                        nf[r] = std::max(nf[r], v);
                    }
                }
            }
        }

        f.swap(nf);
        nf.assign(10, -inf64);  
    }

    std::cout << *std::max_element(f.begin(), f.end());
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