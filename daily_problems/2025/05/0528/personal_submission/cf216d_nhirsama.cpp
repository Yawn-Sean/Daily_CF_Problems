//  D. Spider's Web
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
#define endl '\n'


void nhir() {
    i32 n;
    std::cin >> n;
    std::vector v(n, std::vector<i32>());
    for (auto &i: v) {
        i32 t;
        std::cin >> t;
        while (t--) {
            i32 a;
            std::cin >> a;
            i.push_back(a);
        }
        std::ranges::sort(i);
    }
    v.push_back(v[0]);
    v.push_back(v[1]);
    i32 ans = 0;
    for (i32 i = 1; i <= n; i++) {
        std::map<i32, i32> m;
        for (auto a: v[i - 1]) {
            m[std::ranges::lower_bound(v[i], a) - v[i].begin()]++;
        }
        for (auto a: v[i + 1]) {
            m[std::ranges::lower_bound(v[i], a) - v[i].begin()]--;
        }
        for (auto [x, y]: m) {
            if (y != 0 && x != 0 && x != v[i].size()) ans++;
        }
    }
    std::cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}
