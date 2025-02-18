#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 998244353;
constexpr int inf32 = 1E9 + 7;

void solve() {
    int b, d;
    std::cin >> b >> d;

    std::string a, c;
    std::cin >> a >> c;

    std::vector<int> nxt(c.size()), cnt(c.size());
    std::iota(nxt.begin(), nxt.end(), 0);

    for (int i = 0; i < c.size(); ++ i) {
        for (char ch : a) {
            if (ch == c[nxt[i]]) {
                if (++ nxt[i] == c.size()) {
                    nxt[i] = 0;
                    ++ cnt[i];
                }
            }
        }
    }

    int tot = 0, cur = 0;

    while (b --) {
        tot += cnt[cur];
        cur = nxt[cur];
    }

    std::cout << tot / d;
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