//  E. Comments
#include <bits/stdc++.h>

using i64 = long long int;
using i32 = long long int;
constexpr int mod = 1e9 + 7;
constexpr char endl = '\n';


void nhir() {
    std::string input;
    std::cin >> input;
    for (auto &i: input) if (i == ',') i = ' ';
    std::stringstream cinn(input);
    std::map<i32, std::vector<std::string> > g2;
    i32 ans = 0;
    auto dfs = [&](this auto &&dfs, i32 d) -> void {
        ans = std::max(ans, d);
        std::string s;
        i32 t;
        if (d == 1) {
            while (cinn >> s >> t) {
                g2[d].push_back(s);
                for (i32 i = 0; i < t; i++) {
                    dfs(d + 1);
                }
            }
        } else {
            cinn >> s >> t;
            g2[d].push_back(s);
            for (i32 i = 0; i < t; i++) {
                dfs(d + 1);
            }
        }
    };
    dfs(1);
    std::cout << ans << endl;
    for (auto [x, y]: g2) {
        for (auto s: y) {
            std::cout << s << ' ';
        }
        std::cout << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    while (T--) nhir();
    return 0;
}
