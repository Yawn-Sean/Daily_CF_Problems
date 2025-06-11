#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;
constexpr int P = 998244353;

void solve() {
    int m;
    std::cin >> m;

    std::string s;
    std::cin >> s;

    int n = s.size();
    
    for (int i = 0; i < 26; ++ i) {
        bool ok = true;

        for (int j = 0, pre = -1; j < n; ++ j) {
            if (s[j] - 'a' <= i)
                pre = j;
            else if(j - pre >= m) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::vector<int> cnt(26);

            for (int j = 0, pre = -1, last = -1; j < n; ++ j) {
                if (s[j] - 'a' < i)
                    ++ cnt[s[j] - 'a'], pre = j;
                else if (s[j] - 'a' == i)
                    last = j;

                if (j - pre >= m) {
                    ++ cnt[s[last] - 'a'];
                    pre = last;
                }
            }

            for (int j = 0; j < 26; ++ j)
                if (cnt[j])
                    std::cout << std::string(cnt[j], j + 'a');
            break;
        }
    }

}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}