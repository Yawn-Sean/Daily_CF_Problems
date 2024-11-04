#include <bits/stdc++.h>
// #include <ranges>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int P = 1E9 + 7;;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;

void solve() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int tot = 0;
    for (char ch : s)
        if (ch == 'G')
            ++ tot;

    int last = -1, lastcnt = 0;

    int ans = 0;

    for (int i = 0, c = 0; i < n; ++ i) {
        if (s[i] == 'G') {
            ++ c;
            if (i - c == last + 1 && tot > c + lastcnt) {
                ans = std::max(ans, c + lastcnt + 1);
            }
        }
        else {
            last = i - 1;
            lastcnt = c;
            c = 0;
        }
        ans = std::max(ans, c);
        if (tot > c)
            ans = std::max(ans, c + 1);
    }

    std::cout << ans;
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