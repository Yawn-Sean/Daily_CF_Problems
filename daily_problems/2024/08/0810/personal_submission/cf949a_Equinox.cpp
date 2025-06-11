#include <bits/stdc++.h>
// #include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1E-9;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> ans;
    std::vector<int> buf0, buf1;
    for (int i = 0; i < s.size(); ++ i) {
        if (s[i] ^ 48) {
            if(buf0.size()) {
                buf1.push_back(buf0.back());
                buf0.pop_back();
                ans[buf1.back()].push_back(i);
            }
            else {
                std::cout << -1;
                return;
            }
        }
        else {
            if (buf1.size()) {
                buf0.push_back(buf1.back());
                buf1.pop_back();
                ans[buf0.back()].emplace_back(i);
            }
            else {
                buf0.push_back(ans.size());
                ans.push_back({i});
            }
        }
    }

    if (buf1.size()) {
        std::cout << -1;
        return;
    }

    std::cout << ans.size() << '\n';

    for (auto& v : ans) {
        std::cout << v.size() << ' ';
        for (int i = 0; i < v.size(); ++ i)
            std::cout << v[i] + 1 << " \n"[i + 1 == v.size()];
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